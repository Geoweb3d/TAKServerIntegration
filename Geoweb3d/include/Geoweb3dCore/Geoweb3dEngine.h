//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2018, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _GEOWEB3D_ENGINE_H_
#define _GEOWEB3D_ENGINE_H_

#include "Geoweb3dExports.h"
#include "Geoweb3dTypes.h"
#include <memory.h>  // will be removed once we remove the memset from our api!

namespace Geoweb3d
{

	/// <summary>	A macro that defines the major Geoweb3d SDK version. </summary>
	#define GEOWEB3D_VERSION_MAJ          (0)
	/// <summary>	A macro that defines the minor Geoweb3d SDK version. </summary>
	#define GEOWEB3D_VERSION_MIN          (10)
	/// <summary>	A macro that defines the Geoweb3d SDK version build number. </summary>
	#define GEOWEB3D_VERSION_BUILDNUM     (1)
	/// <summary>	A macro that defines the Geoweb3d SDK version revision number. </summary>
	#define GEOWEB3D_VERSION_REVISION     (1)




//SKIP-CODE-BEGIN

	//Note, this will return an -1 if infinteZ is not in stereo on this window 
	//or if the InfiniteZ sdk is not installed
	//GEOWEB3DENGINE_API	int	GetInfintiteZTrackerNumOfButtons( CameraHandle camera_handle );
	//GEOWEB3DENGINE_API bool GetInfintiteZTrackerisButtonPressed( CameraHandle camera_handle, int button );

	
//	GEOWEB3DENGINE_API GW3DResult SetHeadTrackerTranslationScale( CameraHandle camera_handle, float scale );
	
	
	//NOTE! EnableHeadTrackerFilter is global....but right now we need a camera handle to get to the correct
	//objects.. TODO
	//GEOWEB3DENGINE_API GW3DResult EnableHeadTrackerFilter(CameraHandle camera_handle, bool filter_on );

	//Note, if any button is pressed I will return true...
	//GEOWEB3DENGINE_API bool GetInfintiteZTrackerInfo(CameraHandle camera_handle, int &screen_coord_x, int &screen_coord_y, float &direction_x, float &direction_y , float &direction_z  );
	//Note, if any button is pressed I will return true...
	//GEOWEB3DENGINE_API bool GetInfintiteZTrackerInfo(CameraHandle camera_handle, double &latitude, double &longitude, double &elevation, float &direction_x, float &direction_y , float &direction_z);

//SKIP-CODE-END

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Window configuration. </summary>
	///
	/// <remarks>	Depricated. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	struct WindowConfig
	{
		WindowConfig() : picture_quality(4),external_opengl_context(false)
		{}

		unsigned picture_quality;
		bool     external_opengl_context;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Multi media capture profile. </summary>
	///
	/// <remarks>	Depricated. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//struct MultiMediaCaptureProfile
	//{
	//	enum OutType
	//	{
	//		WMVFile,	   //save to a file
	//		ASFNetworking, //let clients connect to this app, port 8080, around 10 connections is ok
	//		NetworkingPushing,  //connects this app to server, enabling broadcast to 1000s.
	//	};

	//	MultiMediaCaptureProfile() 
	//		: outputype( ASFNetworking ) //network is the default
	//		, networkport(8080) //port if streaming/network
	//		, bitrate(768*1000) //768 for dsl, etc...
	//		, quality(90) // 1 to 100
	//	{
	//		memset(&title,0,sizeof(title));
	//		memset(&author,0,sizeof(author));
	//		memset(&copyright,0,sizeof(copyright));
	//		memset(&description,0,sizeof(description));
	//		memset(&fullfilenameorURL,0,sizeof(fullfilenameorURL));
	//	}

	//	OutType outputype;
	//	int networkport;

	//	int bitrate;
	//	int quality;
	//	char title[64];
	//	char author[64];
	//	char copyright[128];
	//	char description[128];
	//	char fullfilenameorURL[512];
	//};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Starts multi media service. </summary>
	///
	/// <remarks>	Depricated. </remarks>
	///
	/// <param name="handle"> 	[in,out] The handle. </param>
	/// <param name="service">	The service. </param>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//GEOWEB3DENGINE_API	GW3DResult	StartMultiMediaService( WindowHandle &handle , const MultiMediaCaptureProfile &service);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Stops all multi media service. </summary>
	///
	/// <remarks>	Depricated. </remarks>
	///
	/// <param name="handle">	[in,out] The handle. </param>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//GEOWEB3DENGINE_API	GW3DResult	StopAllMultiMediaService( WindowHandle &handle );

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets multi media service from filename or URL. </summary>
	///
	/// <remarks>	depricated. </remarks>
	///
	/// <param name="handle">	[in,out] The handle. </param>
	///
	/// <returns>	null if it fails, else the multi media service filename or URL. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//GEOWEB3DENGINE_API	const char*	GetMultiMediaServiceFilenameOrURL( WindowHandle &handle );
	
	//For the CPP API
	class IGW3DIBaseObject;
	struct IGW3DCallback;



};//end namespace

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destroys the class instance described by p. </summary>
	///
	/// <param name="p">	[in,out] If non-null, the Geoweb3d::IGW3DIBaseObject * to process. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	extern "C" GEOWEB3DENGINE_API void destroyClassInstance(  Geoweb3d::IGW3DIBaseObject *p );

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Creates class instance. </summary>
	///
	/// <param name="class_type">	Type of the class. </param>
	/// <param name="p">		 	[in,out] If non-null, the Geoweb3d::IGW3DCallback * to process. </param>
	///
	/// <returns>	null if it fails, else the new class instance. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	extern "C" GEOWEB3DENGINE_API Geoweb3d::IGW3DIBaseObject *createClassInstance( const Geoweb3d::GW3DGUID &class_type, Geoweb3d::IGW3DCallback *p );

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Queries if class interface is supported class interface. </summary>
	///
	/// <param name="class_type">	Type of the class. </param>
	///
	/// <returns>	true if class interface supported, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	extern "C" GEOWEB3DENGINE_API bool isClassInterfaceSupported( const Geoweb3d::GW3DGUID &class_type);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deleter for IGW3DIBaseObject. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	struct IGW3DDeleter
	{
		void operator()( Geoweb3d::IGW3DIBaseObject * p )
		{		
			destroyClassInstance( p );
		}
	};


	template<class T, class C> 
	static T CreateInterfacePtr(const Geoweb3d::GW3DGUID &guid, Geoweb3d::IGW3DCallback *p = 0) 
	{ 
		if(isClassInterfaceSupported( guid ))
		{
			return T(dynamic_cast<C*>(createClassInstance( guid, p )) , IGW3DDeleter() );
		}
		else
		{
			//print error
		}

		return T();
	}

#endif