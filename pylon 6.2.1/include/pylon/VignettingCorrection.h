//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  HK,TvdM
//-----------------------------------------------------------------------------
/*!
  \file
*/
#ifndef INCLUDED_PYLON_VIGNETTINGCORRECTION_H_5ED10A66
#define INCLUDED_PYLON_VIGNETTINGCORRECTION_H_5ED10A66

#pragma once
#include <pylon/Platform.h>
#include <pylon/stdinclude.h>
#include <pylon/PylonUtility.h>
#include <pylon/Image.h>
#include <vector>

namespace Pylon
{
    namespace internal
    {

        /*! \brief Compute parameter for vignetting correction
        \param[in] Image : the homogeneously illuminated image
        \param[in] parameterdatatransferblock : Buffer for the vignetting correction parameter which is transferred to the camera, set to NULL to calculate necessary size
        \param[in,out] datasize :size of the buffer. If  parameterdatatransferblock is NULL, the size of the buffer required is returned
        \param[out] fErrorMeasure: error measurement, something like mean square error
        \return Return true if parameter were computed and copied into the result buffer.
        */
        bool PYLONUTILITY_API ComputeVignettingCorrectionParameter( IImage& Image, uint8_t* parameterdatatransferblock, size_t& datasize, double& fErrorMeasure );
    }

}
#endif // INCLUDED_PYLON_VIGNETTINGCORRECTION_H_5ED10A66
