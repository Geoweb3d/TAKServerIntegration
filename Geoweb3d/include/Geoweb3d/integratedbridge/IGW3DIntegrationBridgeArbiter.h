//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2019, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/GeoWeb3dEngine.h>
#include <Geoweb3dCore/Geoweb3dTypes.h>
#include <Geoweb3d/core/GW3DGuidsHelper.h>

#ifdef __cplusplus

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A macro that defines gw 3 dextern c. </summary>
///
/// <remarks>	Geoweb3d, 11/2/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

#define GW3DEXTERN_C    extern "C"
#else
#define GW3DEXTERN_C    extern
#endif

GW3D_DEFINE_GUID( GUID_GEOWEB3D_SDK_INTEGRATED_BRIDGE_ARBITER , 0x53f58f47, 0x1fa0, 0x4728, 0xac, 0x72, 0x5f, 0xd3, 0x7c, 0x57, 0x8, 0x30);

/*! Primary namespace */
namespace Geoweb3d
{

	//////////////////////////////////
	struct IGW3DIntegrationBridgeArbiter : public IGW3DIBaseObject
	{
		struct IGW3DIntegrationBridgeArbiterInitiStruct
		{
			IGW3DLineSegmentIntersectionTestWPtr hover_and_click_intersectiontest;
		};

		virtual GW3DResult Initialize( IGW3DIntegrationBridgeArbiterInitiStruct *p ) = 0;
		virtual IGW3DBridgedWindowCommunicator* get_BridgedWindowCommunicator() = 0;

		static IGW3DIntegrationBridgeArbiterPtr CreateInterface()
		{
			return CreateInterfacePtr< IGW3DIntegrationBridgeArbiterPtr, IGW3DIntegrationBridgeArbiter>( GUID_GEOWEB3D_SDK_INTEGRATED_BRIDGE_ARBITER );
		}
	};
}
