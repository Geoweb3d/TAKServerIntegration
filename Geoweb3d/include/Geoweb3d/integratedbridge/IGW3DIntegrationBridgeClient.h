//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3dCore/Geoweb3dEngine.h>
#include <Geoweb3d/core/GW3DGuids.h>
#include <Geoweb3d/core/GW3DGuidsHelper.h>
#include "IGW3DSDKVectorContext.h"
#include "IGW3DSDKRasterContext.h"
#include "IGW3DBridgedWindowCallbacks.h"

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


/*! Primary namespace */
namespace Geoweb3d
{
	struct  GW3D_DLL IGW3DBridgedIdentityTest;
	
	struct  GW3D_DLL IGW3DIntegrationBridgeClient : public IGW3DIBaseObject
	{
		virtual GW3DResult  InitializeLibrary() = 0;

		virtual IGW3DSDKContextWPtr get_IGW3DSDKContext() = 0;

		virtual IGW3DSDKVectorContextWPtr get_IGW3DSDKVectorContext() = 0;

		virtual IGW3DSDKRasterContextWPtr get_IGW3DSDKRasterContext() = 0;

		virtual IGW3DPanoramicViewshedTestWPtr create_PanoramicViewshedTest() = 0;

		virtual IGW3DSlopeAnalysisWPtr create_SlopeAnalysis() = 0;

		virtual IGW3DGeoFenceWPtr create_GeoFence(IGW3DVectorLayerWPtr layer, const char* geo_fence_intruder, const char* name) = 0;

		virtual IGW3DColorLookupTablePtr create_ColorLookupTable(int min_value, int max_value) = 0;

		virtual IGW3DImageCollectionPtr create_ImageCollection() = 0;

		virtual IGW3DOpenGLTextureCollectionPtr create_OpenGLTextureCollection() = 0;

		virtual void destroy_PanoramicViewshedTest(IGW3DPanoramicViewshedTestWPtr) = 0;

		virtual void destroy_SlopeAnalysis(IGW3DSlopeAnalysisWPtr) = 0;

		virtual void destroy_GeoFence(IGW3DGeoFenceWPtr) = 0;

		virtual IGW3DBridgedIdentityTest* get_GW3DBridgedIdentityTest() = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	A IGW3DIntegrationBridgeClientPtr </summary>
		///
		/// <param name="pcallback">	(optional) an IGW3DBridgedWindowCallbacks object 
		////////////////////////////////////////////////////////////////////////////////////////////////////
		static IGW3DIntegrationBridgeClientPtr CreateInterface( IGW3DBridgedWindowCallbacks* pcallback = 0 )
		{
			return CreateInterfacePtr< IGW3DIntegrationBridgeClientPtr, IGW3DIntegrationBridgeClient>(GUID_GEOWEB3D_SDK_INTEGRATED_BRIDGE_CLIENT, pcallback);
		}
	};
}
