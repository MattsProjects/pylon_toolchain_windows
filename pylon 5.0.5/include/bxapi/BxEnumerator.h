//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the Enumerator interface (top-level) used for discovering BXAPI devices.
 * \ingroup public
 */
#pragma once

#if _POSIX_C_SOURCE
#  include <inttypes.h>
#endif //
#include <stddef.h> // size_t
#include <bxapi/BxDll.h>
#include <bxapi/BxTypes.h>
#include <bxapi/BxStatus.h>


#pragma pack(push, BX_PACKING)


EXTERN_C_BEGIN

/// Device information block, returned from Enumeration
typedef struct BxapiDeviceDiscoveryInfo_tag
{
    char       BconAdapterDeviceID[BXAPI_DEVINFOMAXSTRINGLENGTH];               ///< Device ID. Used to communicate with BCON adapter API.
    uint8_t    DeviceIdx;                                                       ///< N-th result of enumeration.

    char       ManufacturerName[BXAPI_DEVINFOMAXSTRINGLENGTH];                  ///< Manufacturer name.
    char       ModelName[BXAPI_DEVINFOMAXSTRINGLENGTH];                         ///< Model name.
    char       FamilyName[BXAPI_DEVINFOMAXSTRINGLENGTH];                        ///< Family name.
    char       DeviceVersion[BXAPI_DEVINFOMAXSTRINGLENGTH];                     ///< Device version.
    char       ManufacturerInfo[BXAPI_DEVINFOMAXSTRINGLENGTH];                  ///< Manufacturer info.
    char       SerialNumber[BXAPI_DEVINFOMAXSTRINGLENGTH];                      ///< Serial number.
    char       UserDefinedName[BXAPI_DEVINFOMAXSTRINGLENGTH];                   ///< User defined name.

    char       AdapterLibrary[BXAPI_DEVINFOMAXSTRINGLENGTH];                    ///< Name of adapter library used including extension, e.g. BconAdapter.dll
    unsigned int AdapterApiMajorVersion;                                        ///< Major Version of API supported by BCON Adapter
    unsigned int AdapterApiMinorVersion;                                        ///< Minor Version of API supported by BCON Adapter
    unsigned int AdapterMajorVersion;                                           ///< Major Version of BCON Adapter
    unsigned int AdapterMinorVersion;                                           ///< Minor Version of BCON Adapter
    unsigned int ApiMajorVersion;                                               ///< Major Version of BCON Adapter API supported by the BXAPI
    unsigned int ApiMinorVersion;                                               ///< Minor Version of BCON Adapter API supported by the BXAPI

} BxapiDeviceDiscoveryInfo;


/**
\brief Discovery callback function. 
This function will be called for each device found during discovery.
The pDiscoveryInfo parameter points to information about the device found. Do not store this pointer as it will be only valid during the callback.
The userContext parameter holds the user defined context passed to BxapiDiscoverDevices() call.
\param BxapiDiscoveryCallback Dummy parameter as it seems doxygen cannot handle function pointers correctly
\return Dummy (see above)
*/
typedef BXSTATUS (BX_CALL *BxapiDiscoveryCallback)(const BxapiDeviceDiscoveryInfo *pDiscoveryInfo, void *userContext);


/**
\brief Discover connected camera devices.
This function scans the system for connected devices. For each device found it will call the function passed in pDiscoveryCallbackFunction. 
\param [in] pDiscoveryCallbackFunction Optional parameter Pointer to a function which will be called for each device found. This parameter can be NULL
\param [in] userContext User defined data passed to the callback function. 
\param [out] pNumDevicesFound On success this parameter to returns the number of devices found. This parameter can be NULL.
\pre The bxapi library is initialized.
\return Status of discovery.
*/
BX_API BXSTATUS BX_CALL BxapiDiscoverDevices(BxapiDiscoveryCallback pDiscoveryCallbackFunction, void *userContext, size_t* pNumDevicesFound);


EXTERN_C_END


#pragma pack(pop)
