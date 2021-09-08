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

#ifndef BASLER_PYLON_BLAZETLPARAMS_H
#define BASLER_PYLON_BLAZETLPARAMS_H

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
namespace BlazeTLParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for DeviceAccessStatus
    enum DeviceAccessStatusEnums
    {
        DeviceAccessStatus_Busy,  //!< The device is already opened by another entity - Applies to: blaze-101
        DeviceAccessStatus_NoAccess,  //!< Device is not available - Applies to: blaze-101
        DeviceAccessStatus_OpenReadOnly,  //!< Opened in Read-Only mode by this GenTL host - Applies to: blaze-101
        DeviceAccessStatus_OpenReadWrite,  //!< Opened in Read/Write mode by this GenTL host - Applies to: blaze-101
        DeviceAccessStatus_ReadOnly,  //!< The GenTL producer has read-only access to the device - Applies to: blaze-101
        DeviceAccessStatus_ReadWrite,  //!< The GenTL producer has full access to the device - Applies to: blaze-101
        DeviceAccessStatus_Unknown  //!< The status is unknown - Applies to: blaze-101
    };

    //! Valid values for DeviceEndianessMechanism
    enum DeviceEndianessMechanismEnums
    {
        DeviceEndianessMechanism_Legacy,  //!< The device endianness is handled according to GenICam Schema 1 0 - Applies to: blaze-101
        DeviceEndianessMechanism_Standard  //!< The device endianness is handled according to GenICam Schema 1 1 and later - Applies to: blaze-101
    };

    //! Valid values for DeviceType
    enum DeviceTypeEnums
    {
        DeviceType_CameraLink,  //!< The transport layer used is Camera Link - Applies to: blaze-101
        DeviceType_CameraLinkHS,  //!< The transport layer used is Camera Link High Speed - Applies to: blaze-101
        DeviceType_CoaXPress,  //!< The transport layer used is CoaXPress - Applies to: blaze-101
        DeviceType_Custom,  //!< Custom transport layer - Applies to: blaze-101
        DeviceType_GigEVision,  //!< The transport layer used is GigE Vision - Applies to: blaze-101
        DeviceType_USB3Vision  //!< The transport layer used is USB3 Vision - Applies to: blaze-101
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!< The selected event notification is disabled - Applies to: blaze-101
        EventNotification_On,  //!< The selected event notification is enabled - Applies to: blaze-101
        EventNotification_Once  //!< The selected event notification is enabled for one event and then returns to Off state - Applies to: blaze-101
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_DeviceLost  //!< Raised when the local host loses the connection to the physical (remote) device - Applies to: blaze-101
    };


    
    
    //**************************************************************************************************
    // Parameter class BlazeTLParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for blaze-101

    blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
    */
    class BlazeTLParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BlazeTLParams(void);

            //! Destructor
            ~BlazeTLParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BlazeTLParams_Data;
        BlazeTLParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: ExtendedDeviceControl
    //@{
    /*!
        \brief Enables the duplication of commands - Applies to: blaze-101

        This feature enables the duplication of commands. This option should only be enabled in case of network problems.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CommandDuplicationEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CommandDuplicationEnable;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates the device's access status at the moment of the last execution of the DeviceUpdateList command - Applies to: blaze-101

        Indicates the device's access status at the moment of the last execution of the DeviceUpdateList command. This value only changes when the DeviceUpdateList command is executed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceAccessStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceAccessStatusEnums>& DeviceAccessStatus;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief User-readable name of the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceDisplayName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceDisplayName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Sets the endianness handling mode - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceEndianessMechanism" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceEndianessMechanismEnums>& DeviceEndianessMechanism;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Interface-wide unique identifier of this device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceID;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Additional information about the manufacturer of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Name of the remote device model - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Serial number of the remote device - Applies to: blaze-101

        Serial number of the remote device. This string is a unique identifier of the device.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSerialNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceSerialNumber;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates the transport layer type of the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTypeEnums>& DeviceType;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Name of the manufacturer of the remote device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;

    //@}


    //! \name Categories: EventDeviceLostData
    //@{
    /*!
        \brief Returns the unique Identifier of the Device Lost type of Event - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventDeviceLost" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventDeviceLost;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Sets whether notifications to the host application of the occurrence of the selected event are enabled or disabled - Applies to: blaze-101

        Sets whether notifications to the host application of the occurrence of the selected event are enabled or disabled
    
        Visibility: Expert

        Selected by: EventSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventNotification" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventNotificationEnums>& EventNotification;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Selects which event to signal to the host application - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: EventNotification

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventSelectorEnums>& EventSelector;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Current gateway IP address of the GVCP interface of the remote device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceGateway;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Current IP address of the GVCP interface of the remote device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceIPAddress;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief 48-bit MAC address of the GVCP interface of the remote device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceMACAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceMACAddress;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Current subnet mask of the GVCP interface of the remote device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceSubnetMask;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Heartbeat timeout value on the host side in milliseconds - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeartbeatTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeartbeatTimeout;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Specifies maximum number of tries before failing the control channel commands - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LinkCommandRetryCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LinkCommandRetryCount;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Specifies application timeout for the control channel communication - Applies to: blaze-101

        Specifies application timeout for the control channel communication. Up to DeviceLinkCommandRetryCount attempts with this timeout are made before a command fails with a timeout error.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LinkCommandTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LinkCommandTimeout;

    //@}


    //! \name Categories: ExtendedDeviceControl
    //@{
    /*!
        \brief Counts the number of timeouts in read and write operations when waiting for the response from the device - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StatisticReadWriteTimeoutCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StatisticReadWriteTimeoutCount;

    //@}


    //! \name Categories: StreamEnumeration
    //@{
    /*!
        \brief Unique device ID of the stream - Applies to: blaze-101

        Unique device ID of the stream. Not mandatory for non-streaming device. Corresponds to the DevGetDataStreamID function with the index corresponding to "StreamSelector".
    
        Visibility: Beginner

        Selected by: StreamSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& StreamID;

    //@}


    //! \name Categories: StreamEnumeration
    //@{
    /*!
        \brief Sets the stream channel to be used  The selector is 0-based in order to match the index of the C interface - Applies to: blaze-101

    
        Visibility: Beginner

        Selecting Parameters: StreamID

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StreamSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StreamSelector;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BlazeTLParams(BlazeTLParams&);

            //! not implemented assignment operator
            BlazeTLParams& operator=(BlazeTLParams&);

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
        class DeviceAccessStatusEnumParameter : public Pylon::CEnumParameterT<DeviceAccessStatusEnums>
        {
        public:
            DeviceAccessStatusEnumParameter()
            {
            }

            virtual ~DeviceAccessStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Busy", 5),
                    TableItem_t("NoAccess", 9),
                    TableItem_t("OpenReadOnly", 13),
                    TableItem_t("OpenReadWrite", 14),
                    TableItem_t("ReadOnly", 9),
                    TableItem_t("ReadWrite", 10),
                    TableItem_t("Unknown", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceEndianessMechanismEnumParameter : public Pylon::CEnumParameterT<DeviceEndianessMechanismEnums>
        {
        public:
            DeviceEndianessMechanismEnumParameter()
            {
            }

            virtual ~DeviceEndianessMechanismEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Legacy", 7),
                    TableItem_t("Standard", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceTypeEnumParameter : public Pylon::CEnumParameterT<DeviceTypeEnums>
        {
        public:
            DeviceTypeEnumParameter()
            {
            }

            virtual ~DeviceTypeEnumParameter()
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
        class EventNotificationEnumParameter : public Pylon::CEnumParameterT<EventNotificationEnums>
        {
        public:
            EventNotificationEnumParameter()
            {
            }

            virtual ~EventNotificationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3),
                    TableItem_t("Once", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class EventSelectorEnumParameter : public Pylon::CEnumParameterT<EventSelectorEnums>
        {
        public:
            EventSelectorEnumParameter()
            {
            }

            virtual ~EventSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("DeviceLost", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BlazeTLParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BlazeTLParams::BlazeTLParams_Data
    {
    public:
        Pylon::CBooleanParameter CommandDuplicationEnable;
        EnumParameterClasses::DeviceAccessStatusEnumParameter DeviceAccessStatus;
        Pylon::CStringParameter DeviceDisplayName;
        EnumParameterClasses::DeviceEndianessMechanismEnumParameter DeviceEndianessMechanism;
        Pylon::CStringParameter DeviceID;
        Pylon::CStringParameter DeviceManufacturerInfo;
        Pylon::CStringParameter DeviceModelName;
        Pylon::CStringParameter DeviceSerialNumber;
        EnumParameterClasses::DeviceTypeEnumParameter DeviceType;
        Pylon::CStringParameter DeviceVendorName;
        Pylon::CIntegerParameter EventDeviceLost;
        EnumParameterClasses::EventNotificationEnumParameter EventNotification;
        EnumParameterClasses::EventSelectorEnumParameter EventSelector;
        Pylon::CIntegerParameter GevDeviceGateway;
        Pylon::CIntegerParameter GevDeviceIPAddress;
        Pylon::CIntegerParameter GevDeviceMACAddress;
        Pylon::CIntegerParameter GevDeviceSubnetMask;
        Pylon::CIntegerParameter HeartbeatTimeout;
        Pylon::CIntegerParameter LinkCommandRetryCount;
        Pylon::CFloatParameter LinkCommandTimeout;
        Pylon::CIntegerParameter StatisticReadWriteTimeoutCount;
        Pylon::CStringParameter StreamID;
        Pylon::CIntegerParameter StreamSelector;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeTLParams::BlazeTLParams(void)
        : m_pData(new BlazeTLParams_Data())
        , CommandDuplicationEnable(m_pData->CommandDuplicationEnable)
        , DeviceAccessStatus(m_pData->DeviceAccessStatus)
        , DeviceDisplayName(m_pData->DeviceDisplayName)
        , DeviceEndianessMechanism(m_pData->DeviceEndianessMechanism)
        , DeviceID(m_pData->DeviceID)
        , DeviceManufacturerInfo(m_pData->DeviceManufacturerInfo)
        , DeviceModelName(m_pData->DeviceModelName)
        , DeviceSerialNumber(m_pData->DeviceSerialNumber)
        , DeviceType(m_pData->DeviceType)
        , DeviceVendorName(m_pData->DeviceVendorName)
        , EventDeviceLost(m_pData->EventDeviceLost)
        , EventNotification(m_pData->EventNotification)
        , EventSelector(m_pData->EventSelector)
        , GevDeviceGateway(m_pData->GevDeviceGateway)
        , GevDeviceIPAddress(m_pData->GevDeviceIPAddress)
        , GevDeviceMACAddress(m_pData->GevDeviceMACAddress)
        , GevDeviceSubnetMask(m_pData->GevDeviceSubnetMask)
        , HeartbeatTimeout(m_pData->HeartbeatTimeout)
        , LinkCommandRetryCount(m_pData->LinkCommandRetryCount)
        , LinkCommandTimeout(m_pData->LinkCommandTimeout)
        , StatisticReadWriteTimeoutCount(m_pData->StatisticReadWriteTimeoutCount)
        , StreamID(m_pData->StreamID)
        , StreamSelector(m_pData->StreamSelector)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeTLParams::~BlazeTLParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BlazeTLParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->CommandDuplicationEnable.Attach(pNodeMap, "CommandDuplicationEnable");
        m_pData->DeviceAccessStatus.Attach(pNodeMap, "DeviceAccessStatus");
        m_pData->DeviceDisplayName.Attach(pNodeMap, "DeviceDisplayName");
        m_pData->DeviceEndianessMechanism.Attach(pNodeMap, "DeviceEndianessMechanism");
        m_pData->DeviceID.Attach(pNodeMap, "DeviceID");
        m_pData->DeviceManufacturerInfo.Attach(pNodeMap, "DeviceManufacturerInfo");
        m_pData->DeviceModelName.Attach(pNodeMap, "DeviceModelName");
        m_pData->DeviceSerialNumber.Attach(pNodeMap, "DeviceSerialNumber");
        m_pData->DeviceType.Attach(pNodeMap, "DeviceType");
        m_pData->DeviceVendorName.Attach(pNodeMap, "DeviceVendorName");
        m_pData->EventDeviceLost.Attach(pNodeMap, "EventDeviceLost");
        m_pData->EventNotification.Attach(pNodeMap, "EventNotification");
        m_pData->EventSelector.Attach(pNodeMap, "EventSelector");
        m_pData->GevDeviceGateway.Attach(pNodeMap, "GevDeviceGateway");
        m_pData->GevDeviceIPAddress.Attach(pNodeMap, "GevDeviceIPAddress");
        m_pData->GevDeviceMACAddress.Attach(pNodeMap, "GevDeviceMACAddress");
        m_pData->GevDeviceSubnetMask.Attach(pNodeMap, "GevDeviceSubnetMask");
        m_pData->HeartbeatTimeout.Attach(pNodeMap, "HeartbeatTimeout");
        m_pData->LinkCommandRetryCount.Attach(pNodeMap, "LinkCommandRetryCount");
        m_pData->LinkCommandTimeout.Attach(pNodeMap, "LinkCommandTimeout");
        m_pData->StatisticReadWriteTimeoutCount.Attach(pNodeMap, "StatisticReadWriteTimeoutCount");
        m_pData->StreamID.Attach(pNodeMap, "StreamID");
        m_pData->StreamSelector.Attach(pNodeMap, "StreamSelector");
    }

    //! \endcond

} // namespace Pylon
} // namespace BlazeTLParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BLAZETLPARAMS_H