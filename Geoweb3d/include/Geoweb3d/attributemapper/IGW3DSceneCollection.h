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

#include <Geoweb3d/core/GW3DInterFace.h>
#include <Geoweb3d/core/IGW3DCollection.h>
namespace Geoweb3d
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Collection of Scene Objects </summary>
///
/// <remarks>	 </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DSceneCollection : public IGW3DCollection< IGW3DSceneWPtr >
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Array indexer operator. </summary>
	///
	/// <param name="index">	Zero-based index of the vector layer. </param>
	///
	/// <returns>	The indexed value. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual const IGW3DSceneWPtr operator[]( unsigned long index ) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets at index. </summary>
	///
	/// <param name="index">	Zero-based index of the vector layer. </param>
	///
	/// <returns>	at index. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual const IGW3DSceneWPtr get_AtIndex( unsigned long index ) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destroys the given scene. </summary>
	///
	/// <param name="scene">	The scene to destroy. </param>
	///
	/// <returns>	GW3D_sOk if succeeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual GW3DResult Destroy( IGW3DSceneWPtr scene ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads a new Scene object from a Geoweb3d Project file (.g3proj) or a Geoweb3d Layer file (.g3lyr)  </summary>
	///
	/// <remarks>	 </remarks>
	///
	/// <param name="filename">	The filename. </param>
	///
	/// <returns>	The new scene. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual IGW3DSceneWPtr Load( const char* filename ) = 0;

};

}