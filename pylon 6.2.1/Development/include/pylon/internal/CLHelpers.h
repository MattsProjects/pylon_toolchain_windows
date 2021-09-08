#if !defined(CL_HELPERS_H_INCLUDED__)
#define CL_HELPERS_H_INCLUDED__

#if defined(_WIN32)

#include <winnt.h>      // for HRESULT
#include <shlobj.h>     // for SHGetFolderPath
#include <Shlwapi.h>    // for PathAppend

#pragma comment(lib, "Kernel32")
#pragma comment(lib, "shlwapi")

// ============================================================
// get the full path to the PortConfiguration file
// the file is located at "<common app data>\Basler\CLBindings\PortConfiguration.xml" for 32 bit platforms and
// "<common app data>\Basler\CLBindings\PortConfiguration_x64.xml" for 64 bit platforms
// ============================================================
size_t GetCLBindingsFullPath( char* pszFullPathToCLBindingsFile, size_t bufferSize )
{
    char szCLBindingsPath[MAX_PATH];
    *szCLBindingsPath = '\0';

    if (::GetEnvironmentVariableA( "PYLON_CL_BINDINGS", szCLBindingsPath, _countof( szCLBindingsPath ) ) == 0 && ::GetLastError() == ERROR_ENVVAR_NOT_FOUND)
    {
        // environment variable not set
        // use CommonAppDataFolder\Basler\CLBindings
        HRESULT hr = ::SHGetFolderPathA( NULL, (CSIDL_COMMON_APPDATA | CSIDL_FLAG_CREATE), NULL, SHGFP_TYPE_CURRENT, szCLBindingsPath );
        if (hr != S_OK) // do not use SUCCEEDED here since the function may return S_FALSE
        {
            return 0;
        }

        // append our own folder beneath the basefolder
        ::PathAppendA( szCLBindingsPath, "Basler\\CLBindings" );
    }

#if defined(_WIN32) && !defined(_WIN64)
    // 32 bit filname
    ::PathAppendA( szCLBindingsPath, "PortConfiguration.xml" );
#elif defined(_WIN32) && defined(_WIN64)
    // 64 bit filename
    ::PathAppendA( szCLBindingsPath, "PortConfiguration_x64.xml" );
#else

#endif

    size_t sizeNeeded = ::lstrlenA( szCLBindingsPath ) + 1; // +1 for term null
    // copy output param
    if (bufferSize >= sizeNeeded && pszFullPathToCLBindingsFile != NULL)
    {
        ::lstrcpyA( pszFullPathToCLBindingsFile, szCLBindingsPath );
    }

    return sizeNeeded;
}

#endif /* _WIN32 */

#endif /* CL_HELPERS_H_INCLUDED__ */
