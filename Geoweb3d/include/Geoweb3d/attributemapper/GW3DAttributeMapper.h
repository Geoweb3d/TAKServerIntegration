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

#include <Geoweb3d/attributemapper/GW3DAttributeMapperExports.h>
#include <Geoweb3d/attributemapper/GW3DGuids.h>
#include <Geoweb3d/attributemapper/GW3DInterFace.h>

#include <Geoweb3dCore/Geoweb3dTypes.h>

/*! Notification functions for SDK feedback */
namespace Geoweb3d
{
namespace SDK_Notification
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Set I/O function. </summary>
///
/// <remarks>	Sets an I/O functions for the user to get verbose information back. </remarks>
///
/// <param name="t">   	The GeoWeb3d_InfoType to process. </param>
/// <param name="func">	The function. </param>
///
/// <returns>	A GeoWeb3d_InfoFunction. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

GW3DATTRIBUTEMAPPER_API GeoWeb3d_InfoFunction GW3DSetAttributeMapperIOFunction( GeoWeb3d_InfoType t, GeoWeb3d_InfoFunction func );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Set default I/O functions. </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

GW3DATTRIBUTEMAPPER_API void GW3DSetAttributeMapperDefaultIOFunctions();

}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destroys the class instance described by p. </summary>
///
/// <param name="p">	[in,out] If non-null, the Geoweb3d::IGW3DIBaseObject * to process. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" GW3DATTRIBUTEMAPPER_API void DestroyClassInstance(  Geoweb3d::IGW3DIBaseObject *p );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates class instance. </summary>
///
/// <param name="class_type">	Type of the class. </param>
/// <param name="p">		 	[in,out] If non-null, the Geoweb3d::IGW3DCallback * to process. </param>
///
/// <returns>	null if it fails, else the new class instance. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" GW3DATTRIBUTEMAPPER_API Geoweb3d::IGW3DIBaseObject* CreateClassInstance( const Geoweb3d::GW3DGUID &class_type, Geoweb3d::IGW3DCallback *p );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Queries if class interface is supported class interface. </summary>
///
/// <param name="class_type">	Type of the class. </param>
///
/// <returns>	true if class interface supported, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" GW3DATTRIBUTEMAPPER_API bool IsClassInterfaceSupported( const Geoweb3d::GW3DGUID &class_type );

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Deleter for IGW3DIBaseObject. </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DInterfaceDeleter
{
	void operator()( Geoweb3d::IGW3DIBaseObject* p )
	{		
		DestroyClassInstance( p );
	}
};


template<class T, class C> 
static T CreateInterfacePointer( const Geoweb3d::GW3DGUID &guid, Geoweb3d::IGW3DCallback *p = 0 ) 
{ 
	if ( IsClassInterfaceSupported( guid ) )
	{
		return T( dynamic_cast<C*>( CreateClassInstance( guid, p ) ), IGW3DInterfaceDeleter() );
	}
	else
	{
		//print error
	}

	return T();
}

