//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2020, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include  "../core/GW3DInterFace.h"

namespace Geoweb3d
{
	struct  GW3D_DLL IGW3DImage;
	extern "C++"
	{
		struct  GW3D_DLL IGW3DRasterLayerEnvelopeStreamResult
		{
			virtual ~IGW3DRasterLayerEnvelopeStreamResult() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Contains the stream result in the form of an image. </summary>
			///
			/// <remarks>	</remarks>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DImage* get_Image() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Contains the stream result in the form of an image. </summary>
			///
			/// <remarks>	Buffer memory should be released when not being used. </remarks>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DImagePtr get_OwnershipOfImage() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Get whether this call back stream object is triggered on a background thread.  </summary>
			///
			/// <remarks>	 </remarks>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual bool get_IsAsynchronous() = 0;

		};
	}
}
