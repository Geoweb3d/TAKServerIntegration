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

/*! Primary namespace */
namespace Geoweb3d
{
	extern "C++"
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	A codec driver. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct GW3D_DLL IGW3DCodecDriver
		{
			virtual ~IGW3DCodecDriver() {}
			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the index. </summary>
			///
			/// <returns>	The index. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual unsigned get_Index() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the name of the driver. </summary>
			///
			/// <returns>	null if it fails, else the name. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const char* get_Name() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the unique identifier. </summary>
			///
			/// <returns>	The unique identifier. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DGUID get_GUID() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Check if VBR is supported. </summary>
			///
			/// <returns>	true if supported, false if not. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual bool get_IsVBRSupported() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets maximum complexity. </summary>>
			///
			/// <returns>	The maximum complexity. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual int get_MaxComplexity() = 0;
		};
	}
}