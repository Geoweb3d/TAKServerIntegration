//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2020, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/GeoWeb3dEngine.h>
#include <Geoweb3dCore/Geoweb3dTypes.h>

namespace Geoweb3d
{
	///////////////////////////////////////////////////////////
	struct IGW3DSDKContext
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	low-level IGW3DGeoweb3dSDK accessor  </summary>
		///
		/// <remarks> This should never be used unless there is a very good reason to. </remarks>
		///
		/// <returns>	the low-level Geoweb3dSDK pointer </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual IGW3DGeoweb3dSDK* get_LowLevelIGW3DGeoweb3dSDK() = 0;
	};
}
