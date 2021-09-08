/****************************************************************************
 Copyright (c) 2010-2021 Basler AG


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
 /// \brief    Implementation for setting up the GenICam environment
 /// \version  $Revision$
 /// \date     $Date$

#ifndef GENICAM_SETUPENVIRONMENTFROMPATH_H
#define GENICAM_SETUPENVIRONMENTFROMPATH_H


//WARNING: IMPLEMENTATION MUST NOT USE ANY RUNTIME FUNCTIONALITY

#include <shlobj.h>
#include <windows.h>
#include <GenICamVersion.h>
#if GENICAM_VERSION_MAJOR > 2
#    define GENICAM_ROOT_VERSION               "GENICAM_ROOT_V" GENICAM_VERSION_MAJOR_STR "_" GENICAM_VERSION_MINOR_STR
#endif
#include <tchar.h>

#ifndef _UNICODE
#error This code is intended to be compiled with unicode character set only
#endif
namespace GenICam
{
    namespace EnvironmentSetup
    {
        ///supports outputting text to debug output
        class CDebugOutput
        {
        public:
            CDebugOutput() : m_traceOn( TraceEnabled() )
            {
            }

                      ///forwards text to debug output if enable -> scrl lock on
            CDebugOutput& operator << ( const _TCHAR* text )
            {
                if (m_traceOn)
                {
                    ::OutputDebugString( text );
                }

                return *this;
            }
        private:
            ///returns true when scrl lock is on!
            bool TraceEnabled()
            {
                // only trace when scrl lock is on!
                return ((::GetKeyState( VK_SCROLL ) && 1) != 0);
            }

            bool m_traceOn; ///<set when object is created
        };

        ///prepends a path with postfix  to the PATH environment variable
        inline bool PrependToPath( const _TCHAR* thePath, const _TCHAR* additionalPostfix )
        {
            //prepend to environment PATH
            bool setPathOk = false;
            const int maxPath = 32767;
            _TCHAR path[maxPath];
            int thePathLength = 0;

            if (thePath == NULL || *thePath == _T( '\0' ))
            {
                return false;
            }


            //copy the path to begin of buffer
            for (const _TCHAR* pThePath = thePath; *pThePath && thePathLength < maxPath; ++pThePath, ++thePathLength)
            {
                path[thePathLength] = *pThePath;
            }

            //append the postfix
            for (const _TCHAR* pPostfix = additionalPostfix; *pPostfix && thePathLength < maxPath; ++pPostfix, ++thePathLength)
            {
                path[thePathLength] = *pPostfix;
            }

            //add path delimiter
            if (thePathLength < maxPath)
            {
                path[thePathLength++] = _T( ';' );
            }
            //add rest of environment path
            if (thePathLength < maxPath)
            {
                int restBufferSize = maxPath - thePathLength;
                int readStringLength = GetEnvironmentVariable( _T( "PATH" ), &path[thePathLength], restBufferSize );
                if (readStringLength)
                {
                    if (readStringLength != restBufferSize) //PATH not already too long
                    {
                        setPathOk = SetEnvironmentVariable( _T( "PATH" ), path ) != 0;
                        CDebugOutput() << _T( "set PATH=" ) << path << _T( "\n" );
                    }
                }
                else //no PATH set yet
                {
                    setPathOk = SetEnvironmentVariable( _T( "PATH" ), thePath ) != 0;
                    CDebugOutput() << _T( "set PATH=" ) << thePath << _T( "\n" );
                }
            }

            return setPathOk;
        }

        inline bool isAsciiString( const _TCHAR* str )
        {
            const _TCHAR* p = str;
            while (*p != 0)
            {
                if (*p > 127)
                    return false;
                p++;
            }
            return true;
        }

        ///sets up the environment for GenICam for the given root path, returns false when failures are detected
        inline bool SetupGenicamEnvironmentFromPath( const _TCHAR* theGenICamRootPath )
        {
            _TCHAR GENICAM_ROOT_VERSION_W[sizeof( GENICAM_ROOT_VERSION )];   // sizeof( GENICAM_ROOT_VERSION) equals length including terminating zero!
            wsprintf( GENICAM_ROOT_VERSION_W, _T( "%hs" ), GENICAM_ROOT_VERSION );
            _TCHAR GENICAM_CACHE_VERSION_W[sizeof( GENICAM_CACHE_VERSION )];
            wsprintf( GENICAM_CACHE_VERSION_W, _T( "%hs" ), GENICAM_CACHE_VERSION );

            //set GenICam root
            bool setRootOk = SetEnvironmentVariable( GENICAM_ROOT_VERSION_W, theGenICamRootPath ) != 0;
            CDebugOutput() << _T( "set " ) << GENICAM_ROOT_VERSION_W << _T( "=" ) << theGenICamRootPath << _T( "\n" );

            //prepend to PATH
#if defined(_WIN64)
            bool setPathOk = PrependToPath( theGenICamRootPath, _T( "\\bin\\Win64_x64" ) );
#else
            bool setPathOk = PrependToPath( theGenICamRootPath, _T( "\\bin\\Win32_i86" ) );
#endif

#if (NTDDI_VERSION >= NTDDI_WIN2K)
            //set GenICam cache
            bool setCacheOk = false;
            {
                const _TCHAR postfix[] = _T( "\\genicam\\xml\\cache" );
                _TCHAR path[MAX_PATH + sizeof postfix];
                _TCHAR shortPath[MAX_PATH];
                //get all user app data dir
                if (SUCCEEDED( SHGetFolderPath( NULL, CSIDL_COMMON_APPDATA, NULL, 0, path ) ))
                {
                    //path append
                    _TCHAR* pPath = path;
                    for (; *pPath; ++pPath);
                    for (const _TCHAR* pPostfix = postfix; *pPostfix; *pPath = *pPostfix, ++pPostfix, ++pPath);
                    *pPath = 0;

                    _TCHAR* pXmlPath = path;

                    if (!GENICAM_NAMESPACE::EnvironmentSetup::isAsciiString( path ))
                    {
                        // get the short path name
                        const unsigned int shortPathLength = GetShortPathName( path, shortPath, sizeof shortPath / sizeof shortPath[0] );
                        if (shortPathLength >= sizeof shortPath || shortPathLength == 0)
                        {
                            GENICAM_NAMESPACE::EnvironmentSetup::CDebugOutput()
                                << _T( "Unable to get short path of " ) << GENICAM_CACHE_VERSION_W << _T( ". Skipping initialization of environment variable.\n" );
                            return setCacheOk;
                        }
                        pXmlPath = shortPath;
                    }

                    //set path
                    setCacheOk = SetEnvironmentVariable( GENICAM_CACHE_VERSION_W, pXmlPath ) != 0;
                    CDebugOutput() << _T( "set " ) << GENICAM_CACHE_VERSION_W << _T( "=" ) << pXmlPath << _T( "\n" );
                }
            }
#else
            bool setCacheOk = true;
#endif
            return setRootOk && setPathOk && setCacheOk;
        }
    }
}

#endif // GENICAM_SETUPENVIRONMENTFROMPATH_H
