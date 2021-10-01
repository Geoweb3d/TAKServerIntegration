//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2020, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include "../core/IGW3DLayer.h"
#include "IGW3DAsyncStreamStatus.h"
#include "IGW3DRasterLayerEnvelopeStream.h"
#include "../../Geoweb3dCore/GeometryExports.h"

/*! Primary namespace */
namespace Geoweb3d
{
	struct   IGW3DWebServiceConfiguration;
	extern "C++"
	{
		struct GW3D_DLL IG3DRasterServiceConfigVisitor
		{
			virtual ~IG3DRasterServiceConfigVisitor() {}

			virtual void visit(IGW3DWebServiceConfiguration*) = 0;

		};

		struct GW3D_DLL IG3DRasterServiceConfiguration
		{
			virtual ~IG3DRasterServiceConfiguration() {}

			//if something bad happened, like the network
			//as disconnected, this object might not be configured
			//and you may get bad information and null objects.
			virtual bool is_valid() const = 0;
			//used for our open APIs that the user can save to disk 
			//what they just configured.
			virtual IGW3DStringPtr get_SerializeToXMLString() const = 0;

			virtual void accept(IG3DRasterServiceConfigVisitor* visitor) = 0;
		};

		struct GW3D_DLL IGW3DWebServiceConfiguration : public IG3DRasterServiceConfiguration
		{
			virtual ~IGW3DWebServiceConfiguration() {}

			virtual void put_CapabilitiesUrl(const char* filepath) = 0;
			virtual IGW3DStringPtr get_CapabilitiesUrl() const = 0;
			virtual void put_CachePath(const char* filepath) = 0;
			virtual IGW3DStringPtr get_CachePath() const = 0;
			virtual void put_CacheExpire(int expireseconds) = 0;
			virtual int  get_CacheExpire() const = 0;
			virtual void put_CacheMaxSize(int maxmegabytes) = 0;
			virtual int  get_CacheMaxSize() const = 0;

			virtual void put_NetworkMaxConnections(int numconnections) = 0;
			virtual int  get_NetworkMaxConnections() const = 0;
			virtual void put_NetworkForceOffline(bool alwaysoffline) = 0;
			virtual bool get_NetworkForceOffline() const = 0;
			virtual void put_NetworkAllowUnsecureConnection(bool nosslcheck) = 0;
			virtual bool get_NetworkAllowUnsecureConnection() const = 0;

			//delimited with a :  example, user:password
			virtual GW3DResult put_ConnectionUsernamePassword(const char* usernamepassword) = 0;
			virtual IGW3DStringPtr get_ConnectionUsernamePassword() const = 0;
		};


		struct GW3D_DLL IGW3DOverviewConfiguration
		{
			virtual ~IGW3DOverviewConfiguration() {}

			virtual int BestOverviewLevel(const Geoweb3d::GW3DEnvelope& wgs84_env, int width, int height) const = 0;
			virtual GW3DResult GetOverviewDPP(int level, double& dppX, double& dppY)  const = 0;
			virtual int GetNumOverviews()  const = 0;

		};
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary> Raster Layer. </summary>
		///
		/// <remarks>	Geoweb3d, 3/23/2020. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		struct GW3D_DLL IGW3DRasterLayer : public IGW3DLayer
		{
			virtual ~IGW3DRasterLayer() {}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets native spatial reference. </summary>
			///
			/// <remarks>	Gets the native spatial reference of the datasource layer. </remarks>
			///
			/// <returns>	The native spatial reference. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DSpatialReferencePtr get_NativeSpatialReference() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets spatial reference. </summary>
			///
			/// <remarks>	Gets the current spatial reference of the layer. </remarks>
			///
			/// <returns>	The spatial reference. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DSpatialReferencePtr get_SpatialReference() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Sets the spatial reference of the datasource layer. </summary>
			///
			/// <remarks>	This does not actually reproject the datasource layer into the given spatial reference.
			/// 			It is for specifying the spatial reference if none exists, or to override it
			/// 			if the native spatial reference is incorrect. </remarks>
			///
			/// <param name="spatialref">	The spatial reference. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void  put_SpatialReference(const IGW3DSpatialReferencePtr spatialref) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Get the spatial envelope. </summary>
			///
			/// <remarks>	This will return the envelope in the WGS84 geographic coordinate system
			///				if put_SpatialReference was not set; otherwise, it will return the envelope 
			///				it the user defined reference.
			/// 			</remarks>
			///
			/// <returns>	The envelope. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DEnvelope get_Envelope() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets attribute definition collection. </summary>
			///
			/// <remarks>	The attribute field definition describes the names, types, etc. of the attribute
			/// 			fields. </remarks>
			///
			/// <returns>	the attribute definition collection. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DDefinitionCollection* get_AttributeDefinitionCollection(bool reset_next_iterator = false) const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the number of pixel along the x coordinate. </summary>
			///
			/// <returns>	The pixel width. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual int  get_Width() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the number of pixel along the y coordinate. </summary>
			///
			/// <returns>	The pixel height. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual int  get_Height() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			 /// <summary>	Gets the pixel size along the x coordinate. </summary>
			 ///
			 /// <returns>	The pixel size (degrees). </returns>
			 ////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual double get_PixelSizeX() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			 /// <summary>	Gets the pixel size along the y coordinate. </summary>
			 ///
			 /// <returns>	The pixel size (degrees). </returns>
			 ////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual double get_PixelSizeY() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the datasource layer description. </summary>
			///
			/// <returns>	The description </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DStringPtr get_Description() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Set the Client User Data. </summary>
			///
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void set_ClientUserData(IGW3DClientUserDataPtr client_data) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the Client User Data.</summary>
			///
			/// <returns>	The Client User Data </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DClientUserDataPtr get_ClientUserData() const = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Gets the raster band collection. </summary>
			///
			/// <remarks>	A collection of all the bands in the raster. </remarks>
			///
			/// <returns>	the raster band collection. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual const IGW3DRasterBandCollection* get_RasterBandCollection(bool reset_next_iterator = false) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	 the Raster Service Configuration object. </summary>
			///
			/// <remarks>	Currently this is used to get the XML for web service datasource layer. </remarks>
			///
			/// <returns>	IG3DRasterServiceConfigurationPtr  </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IG3DRasterServiceConfigurationPtr create_RasterServiceConfiguration() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	 The Overview Configuration. </summary>
			///
			/// <remarks>	Used to access an object that contains details about overviews.  </remarks>
			///
			/// <returns>	const IGW3DOverviewConfiguration*  </returns>

			virtual const IGW3DOverviewConfiguration* get_OverviewConfiguration() = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Streams the Request set forth with IGW3DRasterLayerEnvelopeStream.  </summary>
			///
			/// <remarks>	 </remarks>
			///
			/// <returns>	The Success of the created resources. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual GW3DResult StreamEnvelope(IGW3DRasterLayerEnvelopeStream* streamobj) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Streams the Request set forth with IGW3DRasterLayerEnvelopeStream.  </summary>
			///
			/// <remarks>	Not all datasource layer support asyc operations right now. If your are async you may be 
			///				able to get detials in the IGW3DStreamStatus where you can also cancel an 
			///				operation. Note the stream results may be on a different thread than than this thread.
			///				</remarks>
			///
			/// <returns>	The Success of the created resources. </returns>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual IGW3DAsyncStreamStatusWPtr StreamEnvelopeAsync(IGW3DRasterLayerEnvelopeStreamWPtr streamobj) = 0;

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Cancels all Asynchronous resources. </summary>
			///
			/// <remarks>	Cancels and waits on all internal tasks to finish. After this call all
			///				there will be no more callbacks into IGW3DRasterLayerEnvelopeStream objects. 
			///				</remarks>
			////////////////////////////////////////////////////////////////////////////////////////////////////

			virtual void ShutDownAsyncStreams() = 0;
		};
	}
}