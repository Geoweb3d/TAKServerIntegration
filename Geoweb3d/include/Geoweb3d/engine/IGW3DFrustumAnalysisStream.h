//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"

namespace Geoweb3d
{
    extern "C++"
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        /// <summary>	The frustum analysis stream  </summary>
        ///
        /// <remarks>	This class is implimented by the SDK user and passed into 
        ///				IGW3DVectorRepresentationDriverCollection::Stream in order to retrieve analysis 
        ///				results from the last frame of rendering. </remarks>
        ///
        ///	<see cref="IGW3DVectorRepresentationDriverCollection::Stream"/>
        ///	<see cref="IGW3DFrustumAnalysis"/>
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        struct  GW3D_DLL IGW3DFrustumAnalysisStream
        {
            virtual ~IGW3DFrustumAnalysisStream(){}
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	OnStream callback  </summary>
            ///
            /// <remarks>	return true to keep streaming.  return false to stop the stream </remarks>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual bool OnStream(IGW3DContentsResult* contents, IGW3DFeatureFeedbackResultCollection* featurefeedback) = 0;

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            /// <summary>	Callback reporting that an error occurred. </summary>
            ///
            /// <remarks>	if error, return true to continue, else false to stop the stream </remarks>
            ////////////////////////////////////////////////////////////////////////////////////////////////////

            virtual bool OnError() = 0;
        };
    }
}