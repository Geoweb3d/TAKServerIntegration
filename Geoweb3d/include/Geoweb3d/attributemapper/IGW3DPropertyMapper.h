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

/*! Primary namespace */
namespace Geoweb3d
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> IGW3DUserPropertyMapper. </summary>
///
/// <remarks> Allows the application to add custum properties to representations. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
class IGW3DPropertyMapper
{
public:
	virtual ~IGW3DPropertyMapper()
	{}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds the user defined property for use during attribute mapping </summary>
	///
	/// <remarks>	</remarks>
	/// <param name="property_name"></param>
	/// <param name="property_alias"></param>
	/// <param name="property_description"></param>
	/// <param name="type"></param>
	/// <param name="default_value"></param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void AddSupportedProperty( const char* property_name, const char* property_alias, const char* property_description, Geoweb3d::PropertyType type, const Geoweb3d::IGW3DVariant& default_value ) = 0;
};

}