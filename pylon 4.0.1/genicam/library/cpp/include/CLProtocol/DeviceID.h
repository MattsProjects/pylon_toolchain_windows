//-----------------------------------------------------------------------------
//  (c) 2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//  Author:  Fritz Dierks
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
*/
#ifndef DEVICEID_H_INCLUDED_
#define DEVICEID_H_INCLUDED_

#include <Base\GCBase.h>
#include <GenApi\PortImpl.h>
#include <CLProtocol\CLAllSerial.h>
#include <CLProtocol\CLProtocol.h>
#include <CLProtocol\ISerial.h>
#include <CLProtocol\CVersion.h>
#include <iostream>
#include <fstream>

namespace CLProtocol
{

    //! Helper class which can sprit DeviceIDs strings into tokens 
    /*! \ingroup PublicInterfaces */
    class CLPROTOCOL_DECL CDeviceID 
    {
    public:
        //! returns the token seperator string
        static const char* GetTokenSeperator();

    public:
        //! Constructor
        CDeviceID();

        //! parse string
        bool FromString(const GenICam::gcstring &DeviceID);

        //! retrieves the directory the CL protocol driver is located in 
        /*!
            \param ReplaceEnvironmentVariables If true environment variables like $(GENICAM_ROOT) 
                   are replaced by their value.
        */
        GenICam::gcstring GetDriverDirectory(const bool ReplaceEnvironmentVariables = true) const;

        //! retrieves the file name of the CL protocol driver 
        GenICam::gcstring GetDriverFileName() const;

        //! retrieves the path of the CL protocol driver is located in 
        GenICam::gcstring GetDriverPath() const;

        //! retrieves the manufacturer name of the camera
        GenICam::gcstring GetCameraManufacturer() const;

        //! retrieves the camera family (may return empty string in case of a template)
        GenICam::gcstring GetCameraFamily() const;

        //! retrieves the camera model (may return empty string in case of a template)
        GenICam::gcstring GetCameraModel() const;

        //! retrieves the camera model's version in any format (may return empty string in case of a template)
        GenICam::gcstring GetCameraVersion() const;

        //! retrieves the camera model's serial number in any format (may return empty string in case of a template)
        GenICam::gcstring GetCameraSerialNumber() const;

        //! retrieves the ShortDeviceID/DeviceIDTemplate without the DriverDriectory and the Driver FileName in front
        GenICam::gcstring GetShortDeviceID() const;

        //! retrieves the DeviceID without the DriverDriectory and the Driver FileName in front
        GenICam::gcstring GetDeviceID(const bool ReplaceEnvironmentVariables = true) const;

    private:
        //! The positions of the tokens within the DeviceID string
        typedef enum
        {
            didDriverDirectory = 0,
            didDriverFileName = 1,
            didCameraManufacturer = 2,
            didCameraFamily = 3,
            didCameraModel = 4,
            didCameraVersion = 5,
            didCameraSerialNumber = 6
        } EDeviceIDIndex;

        //! The tokens which form the DeviceID
        GenICam::gcstring_vector m_DeviceIDTokens;

    };

}
#endif // DEVICEID_H_INCLUDED_
