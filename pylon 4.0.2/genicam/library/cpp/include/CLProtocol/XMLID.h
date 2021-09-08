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
#ifndef XMLID_H_INCLUDED_
#define XMLID_H_INCLUDED_

#include <Base\GCBase.h>
#include <CLProtocol\CVersion.h>

namespace CLProtocol
{

    //! Helper class which can sprit XMLIDs strings into tokens 
    /*! \ingroup PublicInterfaces */
    class CLPROTOCOL_DECL CXMLID 
    {
    public:
        //! returns the token seperator string
        static const char* GetTokenSeperator();
    
        //! Constructor
        CXMLID();

        //! Parses the XML ID
        bool FromString(const GenICam::gcstring &XMLID);

        //! Returns the original XML ID
        GenICam::gcstring ToString();

        //! retrieves the schema version of the XML file
        CVersion GetSchemaVersion() const;

        //! retrieves the schema version of the XML file
        CVersion GetDeviceVersion() const;

        //! retrieves the schema version of the XML file
        GenICam::gcstring GetDeviceIDTemplate() const;

        //! Comparison (for sorting)
        bool operator>(CXMLID& XMLID);

    private:
        //! The positions of the tokens within the XMLID string
        typedef enum
        {
            xidSchemaVersion = 0,
            xidDeviceIDTemplate = 1,
            xidDeviceVersion = 2
        } EXMLIDIndex;

        //! The original string
        GenICam::gcstring m_XMLID;

        //! The middle part of the XML ID
        GenICam::gcstring m_DeviceIDTemplate;

        //! The first part of the XML ID
        CVersion m_SchemaVersion;

        //! The last part of the XML ID
        CVersion m_DeviceVersion;
    };


    //! for sorting a vector of pointers to CXMLID objects
    /*! returns true if pA comes before pB */
    inline bool CompareCXMLID( CXMLID *pA, CXMLID *pB )
    {
        return *pA > *pB;
    };


}
#endif 
