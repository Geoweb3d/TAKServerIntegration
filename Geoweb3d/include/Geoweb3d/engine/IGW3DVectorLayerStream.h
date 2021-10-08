//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include "IGW3DVectorLayerStreamFilter.h"



/*! Primary namespace */
namespace Geoweb3d
{
/// ///////////////////////////////////////////////////////////////////////
/// <summary>A vector layer stream.</summary>
/// <remarks>A vector layer stream allows the SDK client to read
///           back the geometry and attributes of vector layer features, as
///           well as modify them if supported by the driver and if the
///           layer has been set as editable.
///           
///           The streamer is implimented by the SDK client. When
///           IGW3DVectorLayer::Stream is called, the SDK will loop through
///           the requested features as defined by the SDK client's
///           implimentation of the IGW3DVectorLayerStreamFilter interface,
///           and will call OnStream for each.</remarks>
///           <see cref="GW3DVectorLayer::get_GeometryEditableMode "/>
///           <see cref="IGW3DVectorLayer::put_GeometryEditableMode"/> 
/// ///////////////////////////////////////////////////////////////////////

struct IGW3DVectorLayerStream : public IGW3DVectorLayerStreamFilter //TODO, make this inherit the userdata
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Executes the stream action for a single vector feature. </summary>
    ///
    /// <remarks>	Geoweb3d, 11/2/2012. </remarks>
    ///
    /// <param name="result">	the result. </param>
    ///
    /// <returns>	true to continue to the next feature, false to abort the stream. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual bool OnStream( IGW3DVectorLayerStreamResult *result ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Executes the error action. </summary>
    ///
    /// <remarks>	This will get called if an error occurs. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

	//return false if you want to cancel
	//otherwise return true to keep going if more exists in the stream
    virtual bool OnError() = 0;

};


}