//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2020 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for blaze-101

blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BLAZESTREAMPARAMS_H
#define BASLER_PYLON_BLAZESTREAMPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for blaze-101
namespace Pylon
{
namespace BlazeStreamParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for AccessMode
    enum AccessModeEnums
    {
        AccessMode_Control,  //!< Applies to: blaze-101
        AccessMode_Exclusive,  //!< Applies to: blaze-101
        AccessMode_Monitor,  //!< Applies to: blaze-101
        AccessMode_NotInitialized  //!< Applies to: blaze-101
    };

    //! Valid values for StreamBufferHandlingMode
    enum StreamBufferHandlingModeEnums
    {
        StreamBufferHandlingMode_NewestOnly,  //!< The application always gets the latest completed buffer (the newest one) - Applies to: blaze-101
        StreamBufferHandlingMode_OldestFirst,  //!< The application always gets the buffer from the head of the output buffer queue (the oldest available) - Applies to: blaze-101
        StreamBufferHandlingMode_OldestFirstOverwrite  //!< The application always gets the buffer from the head of the output buffer queue (the oldest available) - Applies to: blaze-101
    };

    //! Valid values for StreamType
    enum StreamTypeEnums
    {
        StreamType_CameraLink,  //!< The transport layer used is Camera Link - Applies to: blaze-101
        StreamType_CameraLinkHS,  //!< The transport layer used is Camera Link High Speed - Applies to: blaze-101
        StreamType_CoaXPress,  //!< The transport layer used is CoaXPress - Applies to: blaze-101
        StreamType_Custom,  //!< A custom transport layer is used - Applies to: blaze-101
        StreamType_GigEVision,  //!< The transport layer used is GigE Vision - Applies to: blaze-101
        StreamType_USB3Vision  //!< The transport layer used is USB3 Vision - Applies to: blaze-101
    };

    //! Valid values for TransmissionType
    enum TransmissionTypeEnums
    {
        TransmissionType_Todo  //!< TODO - Applies to: blaze-101
    };

    //! Valid values for Type
    enum TypeEnums
    {
        Type_SocketDriver,  //!< The socket driver - Applies to: blaze-101
        Type_WindowsFilterDriver  //!< The Pylon GigE Vision Streaming Filter Driver - Applies to: blaze-101
    };


    
    
    //**************************************************************************************************
    // Parameter class BlazeStreamParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for blaze-101

    blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
    */
    class BlazeStreamParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BlazeStreamParams(void);

            //! Destructor
            ~BlazeStreamParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BlazeStreamParams_Data;
        BlazeStreamParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: Debug
    //@{
    /*!
        \brief Camera access mode - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AccessMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AccessModeEnums>& AccessMode;

    //@}


    //! \name Categories: IPConfig
    //@{
    /*!
        \brief Specifies the destination IP address - Applies to: blaze-101

        The camera will sent all stream data to this IP address. For more details see 'TransmissionType' feature.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DestinationAddr" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DestinationAddr;

    //@}


    //! \name Categories: IPConfig
    //@{
    /*!
        \brief Specifies the destination port number (0 = auto select) - Applies to: blaze-101

        
        
            The camera will sent all stream data to this port.

            <b>Port configuration:</b>
            <ol>
            <li>
                <b>Unicast</b><br>
                The port is determined automatically.
                Manually choosing a port number might be useful for certain firewall configurations.
            </li>
            <br>
            <li>
                <b>Broadcast & Multicast</b><br>
                For each device reachable by a specific network interface, a unique, unused port number
                must be assigned. Be aware that the suggested default value might be already in use.
                Choose an unused port or 0=autoselect in that case. The controlling application and all 
                monitor applications must use the same port number. There is no autoselect feature
                availbale for monitor applications, i.e., monitor applications must not use the 0 value.
                For monitor applications it is convenient to use the 'UseCameraConfig' value for the 
                'TransmissionType' feature instead. For more details see the 'TransmissionType' feature.
            </li>
            </ol>
        
      
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DestinationPort" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DestinationPort;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Enables or disables the packet resend mechanism - Applies to: blaze-101

        
        
        An image frame consists of n numbers of packets. Each packet has a header consisting of a 24-bit packet ID. 
        This packet ID increases with each packet sent, and makes it possible for the receiving end to know if a 
        particular packet has been lost during the transfer. If 'ResendPacketMechanism' is enabled, and the receiving
        end notices a lost packet, it will request the other side (e.g. the camera) to send the lost packet again.
        If enabled, the 'ResendPacketMechanism' can cause delays in the timing because the sending end will resend 
        the lost packet. If disabled, image data packet(s) can get lost which results in an incomplete received frame.
        You have to weigh the disadvantages and advantages for your special application to decide whether to enable 
        or disable this command.<br><br>
        
        Default setting: <i>Enabled</i>
        
      
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EnableResend" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& EnableResend;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Maximum time in milliseconds to receive all packets of an individual frame - Applies to: blaze-101

        
        
      An image frame consists of n numbers of packets. The 'FrameRetention' always starts from the
      point in time the receiving end notices that a packet has been received for a particular frame. 
      If the transmission of packets of a frame is not completed within the 'FrameRetention' time, 
      the corresponding frame is delivered with status 'Failed'.
      
      
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameRetention" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameRetention;

    //@}


    //! \name Categories: ExtendedStreamControl and Root
    //@{
    /*!
        \brief Maximum buffer size in bytes that can be registered - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaxBufferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaxBufferSize;

    //@}


    //! \name Categories: ExtendedStreamControl and Root
    //@{
    /*!
        \brief Maximum number of buffers that can be used simultaneously - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaxNumBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaxNumBuffer;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Maximum number of resend requests per packet - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MaximumNumberResendRequests" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MaximumNumberResendRequests;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Timeout period in milliseconds between two packets within one frame - Applies to: blaze-101

        
        
        An image frame consists of n numbers of packets. The packet timeout counting is (re)started
        each time a packet is received. If the timeout expires (e.g. no packet was received 
        during the last 'PacketTimeout' period), the 'Resend Packet Mechanism' is started. 
        For information, see the 'EnableResend' feature.
        
      
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PacketTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PacketTimeout;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Thread priority of the receive thread - Applies to: blaze-101

        Thread priority of the receive thread. To assign the priority, the Receive Thread Priority Override parameter must be set to true.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReceiveThreadPriority" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ReceiveThreadPriority;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Enables assigning a custom priority to the thread which receives incoming stream packets - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReceiveThreadPriorityOverride" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReceiveThreadPriorityOverride;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Size of the sliding receive window in number of frames - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReceiveWindowSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ReceiveWindowSize;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Additional resend batching as percentage of threshold - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResendRequestBatching" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResendRequestBatching;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Timeout in milliseconds for missing resend responses - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResendRequestResponseTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResendRequestResponseTimeout;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Resend threshold as percentage of receive window - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResendRequestThreshold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResendRequestThreshold;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Time in milliseconds to wait until a resend request is issued - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResendTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResendTimeout;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief The socket buffer size in KB - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SocketBufferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SocketBufferSize;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of frames lost because there were no buffers queued to the driver - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Buffer_Underrun_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Buffer_Underrun_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of buffers with at least one failed packet (status != success) - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Failed_Buffer_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Failed_Buffer_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of failed packets (status != success) - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Failed_Packet_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Failed_Packet_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of packets requested by PACKETRESEND commands - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Resend_Packet_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Resend_Packet_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of emitted PACKETRESEND commands - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Resend_Request_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Resend_Request_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of received frames - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Total_Buffer_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Total_Buffer_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Counts the number of received packets - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Statistic_Total_Packet_Count" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Statistic_Total_Packet_Count;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Minimum number of buffers that have to be announced to enable selected buffer handling mode - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamAnnounceBufferMinimum" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamAnnounceBufferMinimum;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of announced (known) buffers in this stream - Applies to: blaze-101

        Number of announced (known) buffers in this stream. This value changes if additional buffers are announced and/or buffers are revoked by the GenTL consumer.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamAnnouncedBufferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamAnnouncedBufferCount;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Alignment size in bytes of the buffer passed to DSAnnounceBuffer - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamBufferAlignment" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamBufferAlignment;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Buffer handling modes available for this data stream: - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamBufferHandlingMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<StreamBufferHandlingModeEnums>& StreamBufferHandlingMode;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of frames delivered since last acquisition start - Applies to: blaze-101

        Number of frames delivered since last acquisition start. This number is reset when the stream is closed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamDeliveredFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamDeliveredFrameCount;

    //@}


    //! \name Categories: StreamInformation
    //@{
    /*!
        \brief Unique device ID of the data stream - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& StreamID;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of buffers in the input buffer pool plus the buffers(s) currently being filled - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamInputBufferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamInputBufferCount;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Flag indicating whether the acquisition engine has started or not - Applies to: blaze-101

        Flag indicating whether the acquisition engine has started or not. This is independent of the acquisition status of the remote device.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamIsGrabbing" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& StreamIsGrabbing;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of frames lost due to queue underrun - Applies to: blaze-101

        Number of frames lost due to queue underrun. This number is initialized with zero when the stream is opened and incremented every time the data could not be acquired because there was no buffer in the input buffer pool. It is reset when the stream is closed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamLostFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamLostFrameCount;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of buffers in the output buffer queue - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamOutputBufferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamOutputBufferCount;

    //@}


    //! \name Categories: BufferHandlingControl
    //@{
    /*!
        \brief Number of frames started in the acquisition engine - Applies to: blaze-101

        Number of frames started in the acquisition engine. This number is incremented every time in case of a new buffer is started and then to be filled (data written to) regardless even if the buffer is later delivered to the user or discarded for any reason. This number is initialized with 0 at the time of opening the stream. It is not reset until the stream is closed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamStartedFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamStartedFrameCount;

    //@}


    //! \name Categories: StreamInformation
    //@{
    /*!
        \brief Indicates the transport layer type of the data stream - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<StreamTypeEnums>& StreamType;

    //@}


    //! \name Categories: IPConfig
    //@{
    /*!
        \brief Controls whether the stream data is sent to a single device or to multiple devices - Applies to: blaze-101

        
        
        <ul>
        <li>
            <b>Default (Unicast)</b><br>
            The camera sends stream data to a single controlling application. Other devices cannot
            receive the stream data.
        </li>
        <br>
        <li>
            <b>Broadcast</b><br>
            The camera sends the stream data to all devices on the network. The application which 
            starts/stops the acquisition is called the controlling application. Other applications
            can receive the stream data. These applications are called monitor applications, because 
            they open the camera in read-only mode. This implies that monitor applications cannot 
            change the camera configuration and they cannot start/stop the image acquisition.
            However, monitor applications can request resend requests for lost stream data packets.
            <br><br>
            Attention: Broadcasting the stream data packets uses a high amount of network bandwidth 
                       because the stream data packets are forwarded to all devices attached to the 
                       network, even if they are not interested in receiving stream data.
        </li>
        <br>
        <li>
            <b>Multicast</b><br>
            Multicasting is very similar to broadcasting. The main advantage of multicasting is that 
            multicasting saves network bandwidth, because the image data stream is only sent to those 
            devices that are interested in receiving the data. To achieve this, the camera sends image 
            data streams to members of a multicast group only. A multicast group is defined by an IP 
            address taken from the multicast address range (224.0.0.0 to 239.255.255.255). 
            <br><br>
            Every device that wants to receive a multicast data stream has to be a member of a multicast 
            group. A member of a specific multicast group only receives data destinated for this group.
            Data for other groups is not received. Usually network adapters and switches are able to filter
            the data efficently on hardware level (layer-2 packet filtering). 
            <br><br>
            When multicasting is enabled for GenTL GEV producer, the GenTL GEV producer automatically takes 
            care of joining and leaving the multicast groups defined by the destination IP address. Keep in 
            mind that some addresses from the multicast address range are reserved for general purposes. 
            The address range from 239.255.0.0 to 239.255.255.255 is assigned by RFC 2365 as a locally 
            administered address space. Use one of these addresses if you are not sure.
            <br><br>
            On protocol level multicasting involves a so-called IGMP message (IGMP = Internet Group Management Protocol).
            To benefit from multicasting, managed network switches should be used. These managed network 
            switches support the IGMP protocol. Managed network switches supporting the IGMP protocol
            will forward multicast packets only if there is a connected device that has joined the
            corresponding multicast group. If the switch does not support the IGMP protocol, multicast
            is equivalent to broadcasting.
            <br><br>
            Recommendation:<br>
            <ul>
                <li>
                    Each camera should stream to a different multicast group.
                </li>
                <li>
                    Streaming to different multicast groups reduces the CPU load and saves network bandwidth 
                    if the network switches supports the IGMP protocol.
                </li>
            </ul>
        </li>
        <br>        
        <li>
            <b>Use camera configuration</b><br>
            This setting is only available if the application has opened the device in monitor mode. If 
            the controlling application has already configured the camera stream channel and has possibly 
            started the acquisition, the monitor application can read all required configuration data 
            from the camera. Additional configuration is not required. This setting can only be used if 
            the controlling application has established the stream channel and the monitor application 
            is started afterwards.
            <br><br>
            Note, when using broadcast and multicast configurations: When there is more than one camera 
            device reachable by one network interface, make sure that for each camera a different port
            number must be assigned. For assigning port numbers, see the 'DestinationPort' feature.
        </li>
        </ul>
        
      
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TransmissionType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TransmissionTypeEnums>& TransmissionType;

    //@}


    //! \name Categories: ExtendedStreamControl
    //@{
    /*!
        \brief Selects the driver type to be used - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Type" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TypeEnums>& Type;

    //@}


    //! \name Categories: Debug
    //@{
    /*!
        \brief Specifies whether the socket driver is currently available - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TypeIsSocketDriverAvailable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TypeIsSocketDriverAvailable;

    //@}


    //! \name Categories: Debug
    //@{
    /*!
        \brief Specifies whether the Pylon GigE Vision Streaming Filter Driver is currently available - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TypeIsWindowsFilterDriverAvailable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TypeIsWindowsFilterDriverAvailable;

    //@}


    //! \name Categories: Debug
    //@{
    /*!
        \brief Specifies whether the Pylon GigE Vision Performance Driver for Intel network controllers is currently available - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TypeIsWindowsIntelPerformanceDriverAvailable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TypeIsWindowsIntelPerformanceDriverAvailable;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BlazeStreamParams(BlazeStreamParams&);

            //! not implemented assignment operator
            BlazeStreamParams& operator=(BlazeStreamParams&);

        //! \endcond
    };

    //**************************************************************************************************
    // Enumeration support classes
    //**************************************************************************************************
    //! \cond HIDE_CLASS_METHODS

    ///////////////////////////////////////////////////////////////////////////
    //
    namespace EnumParameterClasses
    {
        ///////////////////////////////////////////////////////////////////////////
        //
        class AccessModeEnumParameter : public Pylon::CEnumParameterT<AccessModeEnums>
        {
        public:
            AccessModeEnumParameter()
            {
            }

            virtual ~AccessModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Control", 8),
                    TableItem_t("Exclusive", 10),
                    TableItem_t("Monitor", 8),
                    TableItem_t("NotInitialized", 15)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class StreamBufferHandlingModeEnumParameter : public Pylon::CEnumParameterT<StreamBufferHandlingModeEnums>
        {
        public:
            StreamBufferHandlingModeEnumParameter()
            {
            }

            virtual ~StreamBufferHandlingModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("NewestOnly", 11),
                    TableItem_t("OldestFirst", 12),
                    TableItem_t("OldestFirstOverwrite", 21)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class StreamTypeEnumParameter : public Pylon::CEnumParameterT<StreamTypeEnums>
        {
        public:
            StreamTypeEnumParameter()
            {
            }

            virtual ~StreamTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CameraLink", 11),
                    TableItem_t("CameraLinkHS", 13),
                    TableItem_t("CoaXPress", 10),
                    TableItem_t("Custom", 7),
                    TableItem_t("GigEVision", 11),
                    TableItem_t("USB3Vision", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TransmissionTypeEnumParameter : public Pylon::CEnumParameterT<TransmissionTypeEnums>
        {
        public:
            TransmissionTypeEnumParameter()
            {
            }

            virtual ~TransmissionTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TypeEnumParameter : public Pylon::CEnumParameterT<TypeEnums>
        {
        public:
            TypeEnumParameter()
            {
            }

            virtual ~TypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("SocketDriver", 13),
                    TableItem_t("WindowsFilterDriver", 20)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BlazeStreamParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BlazeStreamParams::BlazeStreamParams_Data
    {
    public:
        EnumParameterClasses::AccessModeEnumParameter AccessMode;
        Pylon::CStringParameter DestinationAddr;
        Pylon::CIntegerParameter DestinationPort;
        Pylon::CBooleanParameter EnableResend;
        Pylon::CIntegerParameter FrameRetention;
        Pylon::CIntegerParameter MaxBufferSize;
        Pylon::CIntegerParameter MaxNumBuffer;
        Pylon::CIntegerParameter MaximumNumberResendRequests;
        Pylon::CIntegerParameter PacketTimeout;
        Pylon::CIntegerParameter ReceiveThreadPriority;
        Pylon::CBooleanParameter ReceiveThreadPriorityOverride;
        Pylon::CIntegerParameter ReceiveWindowSize;
        Pylon::CIntegerParameter ResendRequestBatching;
        Pylon::CIntegerParameter ResendRequestResponseTimeout;
        Pylon::CIntegerParameter ResendRequestThreshold;
        Pylon::CIntegerParameter ResendTimeout;
        Pylon::CIntegerParameter SocketBufferSize;
        Pylon::CIntegerParameter Statistic_Buffer_Underrun_Count;
        Pylon::CIntegerParameter Statistic_Failed_Buffer_Count;
        Pylon::CIntegerParameter Statistic_Failed_Packet_Count;
        Pylon::CIntegerParameter Statistic_Resend_Packet_Count;
        Pylon::CIntegerParameter Statistic_Resend_Request_Count;
        Pylon::CIntegerParameter Statistic_Total_Buffer_Count;
        Pylon::CIntegerParameter Statistic_Total_Packet_Count;
        Pylon::CIntegerParameter StreamAnnounceBufferMinimum;
        Pylon::CIntegerParameter StreamAnnouncedBufferCount;
        Pylon::CIntegerParameter StreamBufferAlignment;
        EnumParameterClasses::StreamBufferHandlingModeEnumParameter StreamBufferHandlingMode;
        Pylon::CIntegerParameter StreamDeliveredFrameCount;
        Pylon::CStringParameter StreamID;
        Pylon::CIntegerParameter StreamInputBufferCount;
        Pylon::CBooleanParameter StreamIsGrabbing;
        Pylon::CIntegerParameter StreamLostFrameCount;
        Pylon::CIntegerParameter StreamOutputBufferCount;
        Pylon::CIntegerParameter StreamStartedFrameCount;
        EnumParameterClasses::StreamTypeEnumParameter StreamType;
        EnumParameterClasses::TransmissionTypeEnumParameter TransmissionType;
        EnumParameterClasses::TypeEnumParameter Type;
        Pylon::CIntegerParameter TypeIsSocketDriverAvailable;
        Pylon::CIntegerParameter TypeIsWindowsFilterDriverAvailable;
        Pylon::CIntegerParameter TypeIsWindowsIntelPerformanceDriverAvailable;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeStreamParams::BlazeStreamParams(void)
        : m_pData(new BlazeStreamParams_Data())
        , AccessMode(m_pData->AccessMode)
        , DestinationAddr(m_pData->DestinationAddr)
        , DestinationPort(m_pData->DestinationPort)
        , EnableResend(m_pData->EnableResend)
        , FrameRetention(m_pData->FrameRetention)
        , MaxBufferSize(m_pData->MaxBufferSize)
        , MaxNumBuffer(m_pData->MaxNumBuffer)
        , MaximumNumberResendRequests(m_pData->MaximumNumberResendRequests)
        , PacketTimeout(m_pData->PacketTimeout)
        , ReceiveThreadPriority(m_pData->ReceiveThreadPriority)
        , ReceiveThreadPriorityOverride(m_pData->ReceiveThreadPriorityOverride)
        , ReceiveWindowSize(m_pData->ReceiveWindowSize)
        , ResendRequestBatching(m_pData->ResendRequestBatching)
        , ResendRequestResponseTimeout(m_pData->ResendRequestResponseTimeout)
        , ResendRequestThreshold(m_pData->ResendRequestThreshold)
        , ResendTimeout(m_pData->ResendTimeout)
        , SocketBufferSize(m_pData->SocketBufferSize)
        , Statistic_Buffer_Underrun_Count(m_pData->Statistic_Buffer_Underrun_Count)
        , Statistic_Failed_Buffer_Count(m_pData->Statistic_Failed_Buffer_Count)
        , Statistic_Failed_Packet_Count(m_pData->Statistic_Failed_Packet_Count)
        , Statistic_Resend_Packet_Count(m_pData->Statistic_Resend_Packet_Count)
        , Statistic_Resend_Request_Count(m_pData->Statistic_Resend_Request_Count)
        , Statistic_Total_Buffer_Count(m_pData->Statistic_Total_Buffer_Count)
        , Statistic_Total_Packet_Count(m_pData->Statistic_Total_Packet_Count)
        , StreamAnnounceBufferMinimum(m_pData->StreamAnnounceBufferMinimum)
        , StreamAnnouncedBufferCount(m_pData->StreamAnnouncedBufferCount)
        , StreamBufferAlignment(m_pData->StreamBufferAlignment)
        , StreamBufferHandlingMode(m_pData->StreamBufferHandlingMode)
        , StreamDeliveredFrameCount(m_pData->StreamDeliveredFrameCount)
        , StreamID(m_pData->StreamID)
        , StreamInputBufferCount(m_pData->StreamInputBufferCount)
        , StreamIsGrabbing(m_pData->StreamIsGrabbing)
        , StreamLostFrameCount(m_pData->StreamLostFrameCount)
        , StreamOutputBufferCount(m_pData->StreamOutputBufferCount)
        , StreamStartedFrameCount(m_pData->StreamStartedFrameCount)
        , StreamType(m_pData->StreamType)
        , TransmissionType(m_pData->TransmissionType)
        , Type(m_pData->Type)
        , TypeIsSocketDriverAvailable(m_pData->TypeIsSocketDriverAvailable)
        , TypeIsWindowsFilterDriverAvailable(m_pData->TypeIsWindowsFilterDriverAvailable)
        , TypeIsWindowsIntelPerformanceDriverAvailable(m_pData->TypeIsWindowsIntelPerformanceDriverAvailable)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeStreamParams::~BlazeStreamParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BlazeStreamParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->AccessMode.Attach(pNodeMap, "AccessMode");
        m_pData->DestinationAddr.Attach(pNodeMap, "DestinationAddr");
        m_pData->DestinationPort.Attach(pNodeMap, "DestinationPort");
        m_pData->EnableResend.Attach(pNodeMap, "EnableResend");
        m_pData->FrameRetention.Attach(pNodeMap, "FrameRetention");
        m_pData->MaxBufferSize.Attach(pNodeMap, "MaxBufferSize");
        m_pData->MaxNumBuffer.Attach(pNodeMap, "MaxNumBuffer");
        m_pData->MaximumNumberResendRequests.Attach(pNodeMap, "MaximumNumberResendRequests");
        m_pData->PacketTimeout.Attach(pNodeMap, "PacketTimeout");
        m_pData->ReceiveThreadPriority.Attach(pNodeMap, "ReceiveThreadPriority");
        m_pData->ReceiveThreadPriorityOverride.Attach(pNodeMap, "ReceiveThreadPriorityOverride");
        m_pData->ReceiveWindowSize.Attach(pNodeMap, "ReceiveWindowSize");
        m_pData->ResendRequestBatching.Attach(pNodeMap, "ResendRequestBatching");
        m_pData->ResendRequestResponseTimeout.Attach(pNodeMap, "ResendRequestResponseTimeout");
        m_pData->ResendRequestThreshold.Attach(pNodeMap, "ResendRequestThreshold");
        m_pData->ResendTimeout.Attach(pNodeMap, "ResendTimeout");
        m_pData->SocketBufferSize.Attach(pNodeMap, "SocketBufferSize");
        m_pData->Statistic_Buffer_Underrun_Count.Attach(pNodeMap, "Statistic_Buffer_Underrun_Count");
        m_pData->Statistic_Failed_Buffer_Count.Attach(pNodeMap, "Statistic_Failed_Buffer_Count");
        m_pData->Statistic_Failed_Packet_Count.Attach(pNodeMap, "Statistic_Failed_Packet_Count");
        m_pData->Statistic_Resend_Packet_Count.Attach(pNodeMap, "Statistic_Resend_Packet_Count");
        m_pData->Statistic_Resend_Request_Count.Attach(pNodeMap, "Statistic_Resend_Request_Count");
        m_pData->Statistic_Total_Buffer_Count.Attach(pNodeMap, "Statistic_Total_Buffer_Count");
        m_pData->Statistic_Total_Packet_Count.Attach(pNodeMap, "Statistic_Total_Packet_Count");
        m_pData->StreamAnnounceBufferMinimum.Attach(pNodeMap, "StreamAnnounceBufferMinimum");
        m_pData->StreamAnnouncedBufferCount.Attach(pNodeMap, "StreamAnnouncedBufferCount");
        m_pData->StreamBufferAlignment.Attach(pNodeMap, "StreamBufferAlignment");
        m_pData->StreamBufferHandlingMode.Attach(pNodeMap, "StreamBufferHandlingMode");
        m_pData->StreamDeliveredFrameCount.Attach(pNodeMap, "StreamDeliveredFrameCount");
        m_pData->StreamID.Attach(pNodeMap, "StreamID");
        m_pData->StreamInputBufferCount.Attach(pNodeMap, "StreamInputBufferCount");
        m_pData->StreamIsGrabbing.Attach(pNodeMap, "StreamIsGrabbing");
        m_pData->StreamLostFrameCount.Attach(pNodeMap, "StreamLostFrameCount");
        m_pData->StreamOutputBufferCount.Attach(pNodeMap, "StreamOutputBufferCount");
        m_pData->StreamStartedFrameCount.Attach(pNodeMap, "StreamStartedFrameCount");
        m_pData->StreamType.Attach(pNodeMap, "StreamType");
        m_pData->TransmissionType.Attach(pNodeMap, "TransmissionType");
        m_pData->Type.Attach(pNodeMap, "Type");
        m_pData->TypeIsSocketDriverAvailable.Attach(pNodeMap, "TypeIsSocketDriverAvailable");
        m_pData->TypeIsWindowsFilterDriverAvailable.Attach(pNodeMap, "TypeIsWindowsFilterDriverAvailable");
        m_pData->TypeIsWindowsIntelPerformanceDriverAvailable.Attach(pNodeMap, "TypeIsWindowsIntelPerformanceDriverAvailable");
    }

    //! \endcond

} // namespace Pylon
} // namespace BlazeStreamParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BLAZESTREAMPARAMS_H