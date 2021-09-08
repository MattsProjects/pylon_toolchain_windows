# Findpylon
# ---------
#
# Try to locate the pylon C++ SDK package.
#
# Search locations:
#   CMake variables:
#       pylon_ROOT_DIR

#   Environment variables:
#       PYLON_DEV_DIR
#       PYLON_ROOT
#   Default installation folders:
#   /opt/pylon (Linux)
#   %PROGRAMFILES%/Basler/pylon 6 (Windows)
#
#
# If found, this will define the following variables:
#
#  pylon_FOUND
#     True if the pylon C++ SDK package has been found.
#
#  pylon_INCLUDE_DIRS
#     List containing needed include directory's for pylon C++ SDK.

# pylon_LIBRARIES
#     List containing needed libraries for linking pylon C++ SDK.
#     Variable is not set and not required when using the Microsoft Visual Studio).
#
# pylon_ROOT_DIR
#     Located root directory.
#
# The following version information related variables are set:
#  pylon_VERSION_MAJOR
#  pylon_VERSION_MINOR
#  pylon_VERSION_PATCH
#  pylon_VERSION : full version string
#
# Imported Targets
# -----------------
#
# If a pylon installation is found, the following imported target is defined:
#
#  pylon::pylon
#
# Example Usage:
# ---------------
#
# find_package(pylon REQUIRED 6.2)
#
# add_executable(foo foo.cpp)
# target_link_libraries(foo pylon::pylon)

include(FindPackageHandleStandardArgs)

# Parses the pylon version number header and returns the pylon version.
#
# Sets the variables
#  pylon_VERSION_MAJOR
#  pylon_VERSION_MINOR
#  pylon_VERSION_PATCH
#  pylon_VERSION
function(pylon_extract_version version_number_file)
    file(STRINGS ${version_number_file} version_numbers REGEX ".*PYLON_VERSION_(MAJOR|MINOR|SUBMINOR).*")
    list(TRANSFORM version_numbers REPLACE ".*PYLON_VERSION_(MAJOR|MINOR|SUBMINOR)[ \t]*([0-9]+).*" "\\2") 
    list(GET version_numbers 0 version_major)
    list(GET version_numbers 1 version_minor)
    list(GET version_numbers 2 version_subminor)
    set(pylon_VERSION_MAJOR ${version_major} PARENT_SCOPE)
    set(pylon_VERSION_MINOR ${version_minor} PARENT_SCOPE)
    set(pylon_VERSION_PATCH ${version_subminor} PARENT_SCOPE)
    set(pylon_VERSION ${version_major}.${version_minor}.${version_subminor} PARENT_SCOPE)
endfunction()

# Parses the _GenICamVersion.h header and returns the GenApi version information
function(genapi_extract_version version_number_file)
    file(STRINGS ${version_number_file} version_numbers REGEX ".*GENICAM_VERSION_(MAJOR|MINOR).*")
    list(TRANSFORM version_numbers REPLACE ".*GENICAM_VERSION_(MAJOR|MINOR)[ \t]*([0-9]+).*" "\\2") 
    list(GET version_numbers 0 version_major)
    list(GET version_numbers 1 version_minor)
    set(genapi_VERSION_MAJOR ${version_major} PARENT_SCOPE)
    set(genapi_VERSION_MINOR ${version_minor} PARENT_SCOPE)
    file(STRINGS ${version_number_file} company_suffix REGEX ".*GENICAM_COMPANY_SUFFIX.*")
    list(TRANSFORM company_suffix REPLACE ".*GENICAM_COMPANY_SUFFIX[ \t]*([^ \t]+)[ \t]*" "\\1")
    set(genapi_COMPANY_SUFFIX ${company_suffix} PARENT_SCOPE)
    file(STRINGS ${version_number_file} compiler REGEX ".*GENICAM_MAIN_COMPILER.*")
    list(TRANSFORM compiler REPLACE ".*.*GENICAM_MAIN_COMPILER[ \t]*([^ \t]+)[ \t]*" "\\1")
    set(genapi_COMPILER ${compiler} PARENT_SCOPE)
endfunction()

set(_pylon_path_hints) # lists locations where to search for pylon

# Figure out where to search for pylon...
# .. first CMake variables...
set(_pylon_path_vars pylon_ROOT_DIR)
foreach(_var IN LISTS _pylon_path_vars)
    if (${_var})
        if (NOT EXISTS ${${_var}})
            message(WARNING "Ignoring variable ${_var} pointing to non existing directory ${${_var}}" )
        else()
            list(APPEND _pylon_path_hints "${${_var}}")
        endif()
    endif()
endforeach()

# ... then some environment variables..
set(_pylon_env_vars PYLON_DEV_DIR PYLON_ROOT)
foreach(_var IN LISTS _pylon_env_vars)
    if (DEFINED ENV{${_var}})
        if (NOT EXISTS $ENV{${_var}})
            message(WARNING "Ignoring environment variable ${_var} pointing to non existing directory $ENV{${_var}}" )
        else()
            list(APPEND _pylon_path_hints "$ENV{${_var}}")
        endif()
    endif()
endforeach()

# ...and finally default installation locations
if (MSVC)
    if(DEFINED ENV{PROGRAMFILES})
        list(APPEND _pylon_path_hints "$ENV{PROGRAMFILES}/Basler/pylon 6")
    endif()
else()
    list(APPEND _pylon_path_hints /opt/pylon)
endif()

list(REMOVE_DUPLICATES _pylon_path_hints)

find_path(pylon_ROOT_DIR NAMES include/pylon/PylonVersionNumber.h
        HINTS
            ${_pylon_path_hints}
        NO_DEFAULT_PATH)

# Check if pylon_ROOT_DIR differs from the one cached from an earlier run.
# If yes, delete cached variables and rerun all searches.
if(DEFINED pylon_last_cached_root)
    if(NOT pylon_last_cached_root STREQUAL pylon_ROOT_DIR)
        set(_pylon_cached_vars pylon_VERSION pylon_INCLUDE_DIR pylon_LIBRARY_DIR pylon_config )
        foreach(_var IN LISTS _pylon_cached_vars)
            if (DEFINED ${_var})
                unset(${_var} CACHE)
            endif()
        endforeach()
    endif()
endif()

set(pylon_last_cached_root ${pylon_ROOT_DIR} CACHE INTERNAL "last pylon root dir" FORCE)
set(pylon_ROOT_DIR ${pylon_ROOT_DIR} CACHE PATH "The location of the pylon C++ API" FORCE)

set(_required_vars
        pylon_ROOT_DIR
        pylon_INCLUDE_DIR
        pylon_VERSION
        )

if (EXISTS ${pylon_ROOT_DIR})
    message(STATUS "pylon_ROOT_DIR=${pylon_ROOT_DIR}")

    find_path(pylon_INCLUDE_DIR
            NAMES pylon/PylonVersionNumber.h
            HINTS ${pylon_ROOT_DIR}/include
            )

    if (MSVC)
        if(pylon_INCLUDE_DIR)
            pylon_extract_version(${pylon_INCLUDE_DIR}/pylon/PylonVersionNumber.h)
            genapi_extract_version(${pylon_INCLUDE_DIR}/_GenICamVersion.h)
        endif()

        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            set(_pylon_lib_path_suffix lib/x64)
        else()
            set(_pylon_lib_path_suffix lib/Win32)
        endif()

        find_path(pylon_LIBRARY_DIR NAMES
            PylonBase_v${pylon_VERSION_MAJOR}_${pylon_VERSION_MINOR}.lib
            HINTS ${pylon_ROOT_DIR}
            PATH_SUFFIXES ${_pylon_lib_path_suffix}
            NO_DEFAULT_PATH)
        list(APPEND _required_vars pylon_LIBRARY_DIR pylonBase)

        set(pylon_LIBRARIES)
        foreach(lib pylonBase pylonGUI pylonUtility)
            find_library(${lib} 
            NAMES ${lib}_v${pylon_VERSION_MAJOR}_${pylon_VERSION_MINOR}
            PATHS ${pylon_LIBRARY_DIR}
            NO_DEFAULT_PATH)
            list(APPEND _required_vars ${lib})
            list(APPEND pylon_LIBRARIES ${${lib}})
        endforeach()

        foreach (lib GCBase GenApi)
            find_library(${lib} 
            NAMES ${lib}_MD_${genapi_COMPILER}_v${genapi_VERSION_MAJOR}_${genapi_VERSION_MINOR}_${genapi_COMPANY_SUFFIX}
            PATHS ${pylon_LIBRARY_DIR}
            NO_DEFAULT_PATH)
            list(APPEND _required_vars ${lib})
            list(APPEND pylon_LIBRARIES ${${lib}})
        endforeach()
    elseif (CMAKE_SYSTEM_NAME STREQUAL Linux)
        # Find pylon-config tool
        find_program(pylon_config
            NAMES pylon-config
            HINTS ${pylon_ROOT_DIR}
            PATH_SUFFIXES bin
            NO_DEFAULT_PATH
        )
        if(pylon_config)
            execute_process(COMMAND ${pylon_config} "--version"
                    OUTPUT_VARIABLE pylon_VERSION
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

            execute_process(COMMAND ${pylon_config} "--libs" "--libs-rpath"
                            OUTPUT_VARIABLE pylon_LIBRARIES
                            OUTPUT_STRIP_TRAILING_WHITESPACE)

            execute_process(COMMAND ${pylon_config} "--cflags-only-I"
                            OUTPUT_VARIABLE pylon_cpp_flags
                            OUTPUT_STRIP_TRAILING_WHITESPACE)
            string(REPLACE "-I" "" pylon_INCLUDE_DIRS ${pylon_cpp_flags})

            execute_process(COMMAND ${pylon_config} "--version-major"
                    OUTPUT_VARIABLE pylon_VERSION_MAJOR
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

            execute_process(COMMAND ${pylon_config} "--version-minor"
                    OUTPUT_VARIABLE pylon_VERSION_MINOR
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

            execute_process(COMMAND ${pylon_config} "--version-subminor"
                    OUTPUT_VARIABLE pylon_VERSION_PATCH
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
        else()
            set(_failure_reason "pylon-config tool not found!")
        endif()
    else()
        message(SEND_ERROR "Platform is not supported.")
    endif()
endif()

if (NOT ${CMAKE_VERSION} VERSION_LESS 3.16 )
    # REASON_FAILURE_MESSAGE argument ist not supported by find_package_handle_standard_args
    # for cmake < 3.16.
    set(_reason_failure_arg REASON_FAILURE_MESSAGE ${_failure_reason})
endif()

find_package_handle_standard_args(pylon
    REQUIRED_VARS ${_required_vars}
    VERSION_VAR pylon_VERSION
    ${_reason_failure_arg}
)

if (pylon_FOUND)
    if (MSVC)
        set(pylon_INCLUDE_DIRS ${pylon_INCLUDE_DIR})
    
        if(NOT TARGET pylon::pylon)
            add_library(pylon::pylon INTERFACE IMPORTED)
            set_target_properties(pylon::pylon PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${pylon_INCLUDE_DIRS}"
                INTERFACE_LINK_LIBRARIES "${pylon_LIBRARIES}"
                INTERFACE_COMPILE_DEFINITIONS "PYLON_NO_AUTO_IMPLIB=1"
            )
        endif()
    elseif (CMAKE_SYSTEM_NAME STREQUAL Linux) 
        if(NOT TARGET pylon::pylon)
            add_library(pylon::pylon INTERFACE IMPORTED)
            set_target_properties(pylon::pylon PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${pylon_INCLUDE_DIRS}"
                INTERFACE_LINK_LIBRARIES "${pylon_LIBRARIES}"
            )
        endif()
    else()
        message(SEND_ERROR "Platform is not supported.")
    endif()
endif()

mark_as_advanced(${_required_vars})

foreach (var pylonBase PylonGUI PylonUtility GCBase GenApi)
    unset(${var})
endforeach()

unset(_pylon_path_hints)
unset(_pylon_path_vars)
unset(_pylon_env_vars)
unset(_failure_reason)
unset(_reason_failure_arg)
unset(_pylon_lib_path_suffix)
unset(_required_vars)
