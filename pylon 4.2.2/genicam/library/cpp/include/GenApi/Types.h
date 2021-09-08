//-----------------------------------------------------------------------------
//  (c) 2006 by Basler Vision Technologies
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
\brief Common types used in the public GenApi interface.
\ingroup GenApi_PublicUtilities
*/

#ifndef GENAPI_TYPES_H
#define GENAPI_TYPES_H

#ifdef _WIN32
#include <objbase.h> // interface
#else
#define interface struct
#endif

#include "Base/GCTypes.h"
#include "Base/GCStringVector.h"

namespace GenApi
{

    //! signed or unsigned integers
    //! \ingroup GenApi_PublicUtilities
    typedef enum _ESign
    {
        Signed,     //!< Integer is signed
        Unsigned,   //!< Integer is unsigned
        _UndefinedSign  //!< Object is not yetinitialized
    } ESign;

    //! access mode of a node
    //! \ingroup GenApi_PublicUtilities
    typedef enum _EAccessMode
    {
        NI,        //!< Not implemented
        NA,        //!< Not available
        WO,        //!< Write Only
        RO,        //!< Read Only
        RW,        //!< Read and Write
        _UndefinedAccesMode,    //!< Object is not yetinitialized
        _CycleDetectAccesMode   //!< used internally for AccessMode cycle detection

    } EAccessMode;

    //! recommended visibility of a node
    //! \ingroup GenApi_PublicUtilities
    typedef enum _EVisibility
    {
        Beginner = 0,        //!< Always visible
        Expert = 1,        //!< Visible for experts or Gurus
        Guru = 2,        //!< Visible for Gurus
        Invisible = 3,    //!< Not Visible
        _UndefinedVisibility  = 99 //!< Object is not yetinitialized
    } EVisibility;

  //! caching mode of a register
  //! \ingroup GenApi_PublicUtilities
  typedef enum _ECachingMode
  {
    NoCache,              //!< Do not use cache
    WriteThrough,         //!< Write to cache and register
    WriteAround,          //!< Write to register, write to cache on read
    _UndefinedCachingMode //!< Not yet initialized
  } ECachingMode;

    //! recommended representation of a node value
    //! \ingroup GenApi_PublicUtilities
    typedef enum _ERepresentation
    {
        Linear,                     //!< Slider with linear behavior
        Logarithmic,                //!< Slider with logarithmic behaviour
        Boolean,                    //!< Check box
        PureNumber,                 //!< Decimal number in an edit control
        HexNumber,                  //!< Hex number in an edit control
        IPV4Address,                  //!< IP-Address
        MACAddress,                 //!< MAC-Address
        _UndefinedRepresentation,
    } ERepresentation;

// this define is required to deal with a spelling error corrected in v1.2
#ifndef NO_UNDEFINEDED_REPRESENTATION
#   define _UndefindedRepresentation _UndefinedRepresentation
#endif

    //! Endianess of a value in a register
    //! \ingroup GenApi_PublicUtilities
    typedef enum _EEndianess
    {
        BigEndian,     //!< Register is big endian
        LittleEndian,   //!< Register is little endian
        _UndefinedEndian  //!< Object is not yetinitialized
    } EEndianess;


    //! Defines if a node name is standard or custom
    //! \ingroup GenApi_PublicUtilities
    typedef enum _ENameSpace
    {
        Custom,            //!< name resides in custom namespace
        Standard,        //!< name resides in one of the standard namespaces
        _UndefinedNameSpace  //!< Object is not yetinitialized
    } ENameSpace;


    //! Defines from which standard namespace a node name comes from
    //! \ingroup GenApi_PublicUtilities
    typedef enum _EStandardNameSpace
    {
        None,            //!< name resides in custom namespace
        GEV,            //!< name resides in GigE Vision namespace
        IIDC,            //!< name resides in 1394 IIDC namespace
        CL,            //!< name resides in camera link namespace
        USB,            //!< name resides in USBnamespace
        _UndefinedStandardNameSpace  //!< Object is not yetinitialized
    } EStandardNameSpace;


    //! Defines the chices of a Yes/No alternaitve
    //! \ingroup GenApi_PublicUtilities
    typedef enum _EYesNo
    {
        Yes = 1,                //!< yes
        No = 0,                 //!< no
        _UndefinedYesNo = 2     //!< Object is not yetinitialized
    } EYesNo;

    //! A list of strings
    //! \ingroup GenApi_PublicImpl
    typedef GenICam::gcstring_vector StringList_t;


    //! typedef for fomula type
    //! \ingroup GenApi_PublicImpl
    typedef enum _ESlope
    {
        Increasing, //!> strictly monotonous increasing
        Decreasing,    //!> strictly monotonous decreasing
        Varying,    //!> slope changes, e.g. at run-time
        Automatic,    //!> slope is determined automatically by probing the function
        _UndefinedESlope  //!< Object is not yetinitialized
    } ESlope;

    //! typedef describing the different validity checks which can be performed on an XML file
    /*! The enum values for a bitfield of lenght uint32_t */
    //! \ingroup GenApi_PublicImpl
    typedef enum _EXMLValidation
    {
        xvLoad      = 0x00000001L,    //!> Creates a dummy node map
        xvCycles    = 0x00000002L,    //!> checks for write and dependency cycles (implies xvLoad)
        xvSFNC      = 0x00000004L,    //!> checks for conformance with the standard feature naming convention (SFNC)
        xvDefault   = 0x00000000L,    //!> checks performed if nothing else is said
        xvAll       = 0xffffffffL,    //!> all possible checks
        _UndefinedEXMLValidation = 0x8000000L //!< Object is not yetinitialized
    } EXMLValidation;

    //! typedef for float notation
    //! \ingroup GenApi_PublicImpl
    typedef enum _EDisplayNotation
    {
        fnAutomatic, //!> the notation if either scientific or fixed depending on what is shorter
        fnFixed,    //!> the notation is fixed, e.g. 123.4
        fnScientific,    //!> the notation is scientific, e.g. 1.234e2
        _UndefinedEDisplayNotation  //!< Object is not yetinitialized
    } EDisplayNotation;

    //! typedef for interface type
    //! \ingroup GenApi_PublicImpl
    typedef enum _EInterfaceType
    {
        intfIValue, //!> IBase interface
        intfIBase, //!> IBase interface
        intfIInteger, //!> IInteger interface
        intfIBoolean, //!> IBoolean interface
        intfICommand, //!> IBoolean interface
        intfIFloat, //!> IFloat interface
        intfIString, //!> IString interface
        intfIRegister, //!> IRegister interface
        intfICategory, //!> ICategory interface
        intfIEnumeration, //!> IEnumeration interface
        intfIEnumEntry, //!> IEnumEntry interface
        intfIPort, //!> IPort interface
    } EInterfaceType;

    //! typedef for link type
    //! \ingroup GenApi_PublicImpl
    typedef enum _ELinkType
    {
        ctAllDependingNodes, //!> All nodes which will be invalidated if this node becomes invalid
        ctAllTerminalNodes, //!> All terminal nodes which may be written to by this node
        ctInvalidators, //!> List of references to nodes which may invalidate this node
        ctReadingChildren, //!> All child nodes which influence this node's AccessMode
        ctWritingChildren, //!> All child nodes which may be written to
        ctDependingChildren, //!> All child nodes which will cause this node to be invalidated
    } ELinkType;
}

#endif // ifndef GENAPI_TYPES_H
