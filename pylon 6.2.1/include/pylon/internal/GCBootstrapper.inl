/****************************************************************************
//  Copyright (c) 2010-2021 Basler AG
//
//  License: This file is published under the license of the EMVA GenICam  Standard Group.
//  A text file describing the legal terms is included in  your installation as 'GenICam_license.pdf'.
//  If for some reason you are missing  this file please contact the EMVA or visit the website
//  (http://www.genicam.org) for a full copy.
//
//  THIS SOFTWARE IS PROVIDED BY THE EMVA GENICAM STANDARD GROUP "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE EMVA GENICAM STANDARD  GROUP
//  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  DATA, OR PROFITS;
//  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  THEORY OF LIABILITY,
//  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.

****************************************************************************/

 /// \file     $Source$
 /// \brief    Contains a static object that sets up the process local environment for GenICam
 /// \version  $Revision$
 /// \date     $Date$
 /// This header is designed to be included in one standalone CPP-file due to the use of pragma init_seg.
 /// When added to an executable or DLL it makes sure that the environment is setup early in the lib segment. 
 /// WARNING, NEVER INCLUDE THIS FILE IN CPP FILES CONTAINING OTHER IMPLEMENTATION
 /// WARNING, IMPLEMENTATION REQUIRES AT LEAST WINDOWS 2000
   
#include <windows.h>
#include <tchar.h>

#ifndef _UNICODE
#error This code is intended to be compiled with unicode character set only
#endif

//SHGetFolderPath requires at least WIN2K: #if (NTDDI_VERSION >= NTDDI_WIN2K)
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500

#include <pylon/internal/GCSetupEnvironmentFromPath.h>


//run static object init as early as possible
# if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable:4073)
#   pragma init_seg(lib)
#   pragma warning(pop)
# endif

extern "C"
{
    ///static object that sets up the process local environment for GenICam
    struct SetupGenICamEnvironment
    {
        ///perform setting up the environment
        SetupGenICamEnvironment()
        {
            GENICAM_NAMESPACE::EnvironmentSetup::CDebugOutput() << _T("pylon boostrapper says hello!\n");
            
            //Set this variable to indicate setup is done for this process already
            const _TCHAR * const cGenICamEnvironmentIsSetup=_T("GENICAM_LOCAL_ENVIRONMENT_IS_SETUP");


#if defined GENICAM_PRIVATE_ROOT
            _TCHAR sGenICamRootSource[ sizeof (GENICAM_PRIVATE_ROOT)] ;
            wsprintf( sGenICamRootSource, _T("%hs"), GENICAM_PRIVATE_ROOT );
#else //else use default
            _TCHAR sGenICamRootSource[ sizeof (GENICAM_ROOT_VERSION)] ;
            wsprintf( sGenICamRootSource, _T("%hs"), GENICAM_ROOT_VERSION );
#endif
            _TCHAR theGenICamRootPath[32767];
            _TCHAR shortPath[32767];

            //check is already setup 
            // (intentionally use GetEnvironmentVariable, since getenv doesn't notice changes made by SetEnvironmentVariable)
            int readStringLength = GetEnvironmentVariable( cGenICamEnvironmentIsSetup, theGenICamRootPath, sizeof theGenICamRootPath / sizeof theGenICamRootPath[0] );
            //if not setup yet
            if ( readStringLength == 0 ) 
            {
                //get genicam root
                _TCHAR *pGenICamRootPath = theGenICamRootPath;
                int readStringLength = GetEnvironmentVariable( sGenICamRootSource, theGenICamRootPath, sizeof theGenICamRootPath / sizeof theGenICamRootPath[0] );
                if ( readStringLength )
                {
                    if ( ! GENICAM_NAMESPACE::EnvironmentSetup::isAsciiString( theGenICamRootPath ) )
                    {
                        const unsigned int shortPathLength = GetShortPathName( theGenICamRootPath, shortPath, sizeof shortPath );
                        if (shortPathLength >= sizeof shortPath || shortPathLength == 0)
                        {
                            GENICAM_NAMESPACE::EnvironmentSetup::CDebugOutput() 
                                << _T("Unable to get short path of ") << sGenICamRootSource << _T(". Skipping GenICam bootstrapping.\n");
                            return;
                        }
                        pGenICamRootPath = shortPath;
                    }

                    //try setting it up
                    bool ok = GENICAM_NAMESPACE::EnvironmentSetup::SetupGenicamEnvironmentFromPath( pGenICamRootPath);
                    //mark as already setup in any case, leave hint if not 100% successful
                    ok = SetEnvironmentVariable( cGenICamEnvironmentIsSetup, ok ? _T("YES") : _T("MAYBE") ) != 0;
                    GENICAM_NAMESPACE::EnvironmentSetup::CDebugOutput() << _T("set ") << cGenICamEnvironmentIsSetup << _T("=") << (ok ? _T("YES") : _T("MAYBE")) << _T("\n");
                }
                else
                {
                    GENICAM_NAMESPACE::EnvironmentSetup::CDebugOutput() 
                        << _T("Environment variable ") << sGenICamRootSource << _T("is not set. Skipping GenICam bootstrapping.\n");
                }
            }
        }
    }
    gGenICamBootstrapper;
}
