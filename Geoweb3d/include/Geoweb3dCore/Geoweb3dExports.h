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

#if defined(_WIN64) || defined(_WIN32)
	#if GEOWEB3DENGINE_EXPORTS
	#	define GEOWEB3DENGINE_API __declspec(dllexport)
	#else
	#	define GEOWEB3DENGINE_API __declspec(dllimport)
	#endif
#elif defined(__ANDROID__) || defined(__linux__)
	#if GEOWEB3DENGINE_EXPORTS
	#	define GEOWEB3DENGINE_API __attribute__((visibility("default")))
	#else 
	#	define GEOWEB3DENGINE_API
	#endif
#else
	#define GEOWEB3DENGINE_API
	#pragma warning Unknown dynamic link import/export semantics.
#endif
