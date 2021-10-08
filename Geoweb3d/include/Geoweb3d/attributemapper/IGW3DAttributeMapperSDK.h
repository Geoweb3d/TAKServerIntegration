//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d Attribute Mapper SDK
// Copyright (c) Geoweb3d, 2008-2017, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include <Geoweb3d/attributemapper/GW3DInterFace.h>
#include <Geoweb3d/attributemapper/GW3DAttributeMapper.h>

namespace Geoweb3d
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	The Attribute Mapper SDK callback. </summary>
///
/// <remarks>	This callback reports when scene files are added or removed from the 
///				Attribute Mapper SDK.
/// 			</remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DWAttributeMapperSDKCallback : public IGW3DCallback
{
	/// <summary>
	/// 
	/// </summary>
	/// <param name="scene"></param>
	virtual void OnSceneAdded( IGW3DSceneWPtr scene ) = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="scene"></param>
	virtual void OnSceneRemoved( IGW3DSceneWPtr scene ) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	An interface for loading scene files. </summary>
///
/// <remarks>	
/// 			The Geoweb3d Attribute Mapping technology is still under early development and is subject to 
/// 			significant change. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DAttributeMapperSDK : public IGW3DIBaseObject
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Initialize the Geoweb3d Attribute Mapper Library </summary>
	///
	/// <remarks>	This must be called before calling any other APIs. </remarks>
	///
	/// <param name="sdk_context">			The Geoweb3d SDK context.  </param>
	/// <param name="productversion_major">	The major product version. </param>
	/// <param name="productversion_minor">	The minor product version. </param>
	///
	/// <returns>	GW3D_sOk if succeeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual GW3DResult InitializeLibrary( Geoweb3d::IGW3DGeoweb3dSDKPtr sdk_context, int productversion_major, int productversion_minor ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the collection of all loaded scenes. </summary>
	///
	/// <remarks> Geoweb3d Project files and Layer files are loaded through the scene collection. </remarks>
	///
	/// <returns>	The scene collection. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual IGW3DSceneCollection* get_SceneCollection( bool reset_next_iterator = false ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Creates the Geoweb3d Attribute Mapping SDK interface. </summary>
	///
	/// <remarks>	Creates an instance of the Geoweb3d Attribute Mapping SDK. </remarks>
	/// <param name="pcallback">	TBD </param>
	/// <returns>	The new interface. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static IGW3DAttributeMapperSDKPtr CreateInterface( /*IGW3DWAttributeMapperSDKCallback *pcallback*/ )
	{
		return CreateInterfacePointer< IGW3DAttributeMapperSDKPtr, IGW3DAttributeMapperSDK>( GUID_GEOWEB3D_ATTRIBUTEMAPPER_SDK, /*pcallback*/ 0 );
	}
};

}
