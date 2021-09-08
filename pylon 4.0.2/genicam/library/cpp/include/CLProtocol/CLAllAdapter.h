//-----------------------------------------------------------------------------
//  (c) 2009 by DALSA
//  Section: Digital Imaging
//  Project: CLProtocol
//  Author:  Eric Bourbonnais
//  $Header$
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
//-----------------------------------------------------------------------------
/*!
\file
\brief    C++ class wrapping CLSerialAll
*/

#ifndef _CLALLADAPTER_H_
#define _CLALLADAPTER_H_

#include "Base/GCBase.h"
#include "CLProtocol/CLAllSerial.h"
#include "CLProtocol/CLException.h"
#include "CLProtocol/CLProtocol.h"
#include "CLProtocol/ISerialAdapter.h"
#include <map>


namespace CLProtocol
{

    template <class T>
    inline void GetFctAddress(HMODULE hModule, T *fctName, const char *pName)
    {
        T tmp = (T) GetProcAddress( hModule, pName);
        *fctName = tmp;
        if( tmp == NULL )
            throw RUNTIME_EXCEPTION("Cannot find function '%s'", pName);
    }

    //! A map holding the pointers to the serial adapters
    typedef std::map<GenICam::gcstring, ISerialAdapter *> SerialPortMap;

    //! Wraps the CLAllSerial.dll
    class CLPROTOCOL_DECL CCLAllAdapter  : public ISerialAdapter
    {
    public:
        //! retrieves  the list of port mapped by PortID
        static void GetPortMap(SerialPortMap &);

        //! Destroy the factory and all its objects
        static void Destroy( ISerialAdapter * pAdapter );

        //! \name ISerialAdapter interface
        //@{ 
        virtual CLINT32 CLPROTOCOL clSerialRead( CLINT8*,CLUINT32*, CLUINT32);
        virtual CLINT32 CLPROTOCOL clSerialWrite(CLINT8 *,CLUINT32 *,CLUINT32);
        virtual CLINT32 CLPROTOCOL clGetSupportedBaudRates(CLUINT32 *);
        virtual CLINT32 CLPROTOCOL clSetBaudRate(CLUINT32);
        virtual CLINT32 SerialInit( void);
        virtual void SerialClose( void);
        virtual void CheckError( CLINT32 ErrorCode );
        //@} 

    private:
        /*------------------------------------------------*/
        // functions of the CLAllSerial DLL
        /*------------------------------------------------*/
        struct CLAllProxy
        {
            //! Function pointer to clGetErrorText
            CLINT32 (CLALLSERIALCC *m_clGetErrorText)( const CLINT8*, CLINT32, CLINT8*, CLUINT32*);
            //! Function pointer to clGetNumPorts
            CLINT32 (CLALLSERIALCC *m_clGetNumPorts) ( CLUINT32* Ports);
            //! Function pointer to  clGetPortInfo
            CLINT32 (CLALLSERIALCC *m_clGetPortInfo ) ( CLUINT32 serialIndex, CLINT8* manufacturerName, CLUINT32* nameBytes, CLINT8* portID, CLUINT32* IDBytes, CLUINT32* version);
            //! Function pointer to clGetSupportedBaudRates
            CLINT32 (CLALLSERIALCC *m_clGetSupportedBaudRates) ( hSerRef serialRef, CLUINT32* baudRates);
            //! Function pointer to clSerialClose
            void (CLALLSERIALCC *m_clSerialClose) ( hSerRef serialRef);
            //! Function pointer to clSerialInit 
            CLINT32 (CLALLSERIALCC *m_clSerialInit) ( CLUINT32 serialIndex, hSerRef* serialRefPtr);
            //! Function pointer to clSerialRead
            CLINT32 (CLALLSERIALCC *m_clSerialRead) ( hSerRef serialRef, CLINT8* buffer, CLUINT32* bufferSize, CLUINT32 serialTimeout);
            //! Function pointer to clSerialWrite
            CLINT32 (CLALLSERIALCC *m_clSerialWrite) ( hSerRef serialRef, CLINT8* buffer, CLUINT32* bufferSize, CLUINT32 serialTimeout);
            //! Function pointer to clSetBaudRate
            CLINT32 (CLALLSERIALCC *m_clSetBaudRate) ( hSerRef serialRef, CLUINT32 baudRate);
        };

        static void CheckError( CLINT32 ErrorCode, CLUINT32 SerialIndex, CLAllProxy & );

        //! Object constructor
        CCLAllAdapter( CLUINT32, CLAllProxy &);

        //! Object destructor
        virtual ~CCLAllAdapter();

        //! handle of the serial port 
        hSerRef m_SerialRef;

        //! Index of the serial port
        CLUINT32 m_SerialIndex;

        //! handle to the loaded ClAllSerial DLL
        HMODULE m_ClAlldllHandle;

        //! CLALL functions pointers
        CLAllProxy m_clallproxy;

        //! the previous baud rate as set via SetBaudRate; zero otherwise
        CLUINT32 m_PreviousBaudRate;

    };
}
#endif //_CLALLADAPTER_H_
