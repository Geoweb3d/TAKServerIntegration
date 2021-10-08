//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d Attribute Mapper SDK
// Copyright (c) Geoweb3d, 2008-2017, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef GEOWEB3D_ATTRIBUTEMAPPER_EXPORTS_HEADER_H
#define GEOWEB3D_ATTRIBUTEMAPPER_EXPORTS_HEADER_H

#ifdef _ATL_ATTRIBUTES
#	define GW3DATTRIBUTEMAPPER_API  
#elif GW3DATTRIBUTEMAPPER_EXPORTS
#	define GW3DATTRIBUTEMAPPER_API __declspec(dllexport)
#else
#	define GW3DATTRIBUTEMAPPER_API __declspec(dllimport)
#endif

#endif
