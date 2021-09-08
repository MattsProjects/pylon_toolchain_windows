#ifndef PRIVATE_FG_PLUGIN_H_INCLUDED
#define PRIVATE_FG_PLUGIN_H_INCLUDED

#include <pylon/Platform.h>

#ifdef FGPLUGIN_EXPORTS
#  define FGPLUGIN_API APIEXPORT
#else
#  define FGPLUGIN_API APIIMPORT
#endif

// can used when finding proc address in DLL
#define FUNC_CREATE_FGPLUGIN_NAME "CreateFrameGrabberObject"
#define FUNC_DESTROY_FGPLUGIN_NAME "DestroyFrameGrabberObject"


namespace Pylon
{

#pragma pack(push, 8)
    // simple struct to provide information about a buffer
    struct BufferDescription
    {
        int     width_px;       // width in pixels
        int     height_px;      // height in pixels
        int     offsetX_px;     // offsetX in pixels
        int     offsetY_px;     // offsetY in pixels
        int     bpp;            // bit per pixel

        size_t  lineSize;       // number of bytes for one line
        size_t  linePitch;      // number of bytes to advance to next line

        size_t  bufferSize;     // total size of the buffer in bytes
        size_t  payloadSize;    // used size of buffer in bytes
        void* pBuffer;        // pointer to pixeldata
        size_t  frameNumber;    // the number of the acquired buffer
        size_t  data1;          // unspecified data
        size_t  data2;          // unspecified data
        int64_t blockID;        // block ID of the acquired buffer

        BufferDescription()
            : width_px( 0 )
            , height_px( 0 )
            , offsetX_px( 0 )
            , offsetY_px( 0 )
            , bpp( 0 )
            , lineSize( 0 )
            , linePitch( 0 )
            , bufferSize( 0 )
            , payloadSize( 0 )
            , pBuffer( NULL )
            , frameNumber( 0 )
            , data1( 0 )
            , data2( 0 )
            , blockID( 0 )
        {
        }

        // return Width in pixel as configured in camera
        int ActualWidth() const
        {
            return static_cast<int>(data1 & INT_MAX);
        }
        // return height in pixel as configured in camera
        int ActualHeight() const
        {
            if (data2 != 0)
            {
                return static_cast<int>(data2 & INT_MAX);
            }
            else
            {   // default to buffer size
                return height_px;
            }
        }
    };
#pragma pack (pop)

    /**
    \brief Interface for a TL's callback functions that are called
       by a FgPlugin */
    struct FgCallee
    {
        typedef bool (*PFUNC_NODECALLBACK)(int64_t val, void* pContext, long lData);

        /// Within this callback the TL has top copy the image data in the TL's buffers
        virtual bool    onBufferAvailable( const BufferDescription* pBufferDesc ) = 0;
        virtual size_t  registerDeviceNodeCallback( const char* pszName, PFUNC_NODECALLBACK pFunc, void* pContext, long lData ) = 0;
        virtual bool    deregisterDeviceNodeCallback( size_t h ) = 0;
        virtual size_t  registerStreamGrabberNodeCallback( const char* pszName, PFUNC_NODECALLBACK pFunc, void* pContext, long lData ) = 0;

          /// Tell the TL that parameters/settings of the device may have been changed and it should invalide its nodemap
//          virtual bool onDeviceParamsChanged(void) = 0;
    };


    enum PoCLPowerSate
    {
        PoCLPowerSate_Error = -2,
        PoCLPowerSate_Unknown = -1,
        PoCLPowerSate_Off = 0,
        PoCLPowerSate_On = 1,
        PoCLPowerSate_Report = 20,
        PoCLPowerSate_Unsupported = 55
    };

    /**
        Interface for a frame grabber class hosted in a frame grabber plugin.

        Use Case: The FG SDK has its own buffer managment. Buffers are passed to the
        pylonTL by a callback. The pylonTL has to copy the data.

    */
    struct FrameGrabber
    {
        virtual bool    Open( const char* pDeviceSpecificParameterString, FgCallee* pCallee ) = 0;
        /// close the streamrabber and free all resources
        virtual void    Close() = 0;
        /// start grabbing images and call callback on pCallee passed in Open
        virtual bool    StartAcquisistion() = 0;
        /// stop grabbing images
        virtual bool    StopAcquisition() = 0;
        /// retrieve descriptive text on last failure
        virtual size_t  GetLastErrorText( char* pErrorMsg, size_t ErrorMsg ) = 0;
        /// for future use (just return NULL)
        virtual size_t  GetDebugData( size_t Reserved ) = 0;
        /// switches PoCL state of the grabber port
        virtual PoCLPowerSate SwitchPowerState( int powerState ) = 0;
    };



    /**
    Preparation of a factory that is able to enumerate frame grabber plugins and to create
    instances of a frame grabber object.

    Until this plugin mechanism is implemented, the implementation of the CreateFg method
    will be hosted by the one and only Coreco frame grabber implementation.
    */
}

// function pointer types for exported functions
typedef Pylon::FrameGrabber* (*PFUNC_CREATE_FGPLUGIN)(const char* pDeviceSpecificParameterString);
typedef bool (*PFUNC_DESTROY_FGPLUGIN)(Pylon::FrameGrabber* pFG);

#endif
