//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2019, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"
#include "IGW3DViewport.h"
#include "IGW3DCameraStereoSettings.h"
#include <Geoweb3dCore/GW3DResults.h>

/*! Primary namespace */
namespace Geoweb3d
{

enum MatrixAccessOrder
{
	MAO_ROW_MAJOR,
	MAO_COL_MAJOR
};

struct IGW3DStereoDeviceNotificationCallbacks
{
	virtual void OnHmdConnected() = 0;
	virtual void OnHmdDisconnected() = 0;
};

struct IGW3DStereoDeviceProjectionMatrixHelper
{
	virtual double get_NearPlane() const = 0;
	virtual double get_FarPlane() const = 0;
	virtual double get_CullingFarPlane() const = 0;
	virtual bool put_ProjectionMatrix( int view_index, double* matrix_data, double* culling_matrix_data, MatrixAccessOrder access_order, bool invert = false ) = 0;
};

struct IGW3DStereoDeviceModelViewMatrixHelper
{
	virtual const double* get_CurrentCameraMatrix( MatrixAccessOrder access_order ) const = 0;
	virtual void put_DeviceRightVector(double x, double y, double z) = 0;
	virtual void put_DeviceViewVector(double x, double y, double z) = 0;
	virtual void put_DeviceUpVector(double x, double y, double z) = 0;
	virtual void put_DeviceRootTransform( double* matrix_data, MatrixAccessOrder access_order, bool invert = false ) = 0;
	virtual bool put_PerViewTransform( int view_index, double* matrix_data, MatrixAccessOrder access_order, bool invert = false ) = 0;
};

struct IGW3DRenderTargetConfigurationHelper
{
	virtual void put_OverrideSurfaceSize( bool override ) = 0;
	virtual void put_Width( int width ) = 0;
	virtual void put_Height( int height ) = 0;
	virtual void put_Samples( int samples ) = 0;
};

struct IGW3DRenderTargetAccessor
{
	virtual const IGW3DViewport* get_WindowViewport() const = 0;
	virtual const IGW3DViewport* get_Viewport( int view_index ) const = 0;
	virtual unsigned int get_TextureId( int view_index ) const = 0 ;
	virtual unsigned int get_TextureWidth( int view_index ) const = 0;
	virtual unsigned int get_TextureHeight( int view_index ) const = 0;
	virtual void CompositeToWindow( int view_index, int x, int y, int w, int h ) = 0;
};

struct IGW3DStereoDeviceCallbacks
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool get_IsInitialized() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="configuration_helper">	</param>
	/// <param name="projection_helper">	</param>
	///
	/// <returns> true if success, false otherwise	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool Initialize( IGW3DRenderTargetConfigurationHelper* configuration_helper, IGW3DStereoDeviceProjectionMatrixHelper* projection_helper ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="projection_helper">	</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void UpdateProjection( IGW3DStereoDeviceProjectionMatrixHelper* projection_helper ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="modelview_helper">	</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void UpdateModelview( IGW3DStereoDeviceModelViewMatrixHelper* modelview_helper )  = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void ProcessEvents( IGW3DStereoDeviceNotificationCallbacks* callbacks ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void OnDrawBegin() = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="render_target_accessor">	</param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void OnDrawEnd( IGW3DRenderTargetAccessor* render_target_accessor ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void OnDrawComplete() = 0;


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the Tracking Origin for a HMD. </summary>
	///
	/// <remarks>	IF active stereo driver does not support this api then GW3D_eNotimpl is returned. </remarks>
	///
	/// <returns>	GW3D_sOk if succeeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual GW3DResult put_TrackingOrigin( IGW3DCameraStereoSettings::TrackingOrigin origin ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the zero pose for the seated tracker coordinate system to the current position 
	///             and yaw of the HMD. </summary>
	///
	/// <remarks>	This function overrides the user's previously saved seated zero pose and should only 
	///             be called as the result of a user action. Users are also able to set their seated 
	///             zero pose via the HMD Dashboard.
	///
	///             IF active stereo driver does not support this api then GW3D_eNotimpl is returned. </remarks>
	///
	/// <returns>	GW3D_sOk if succeeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual GW3DResult reset_SeatedZeroPose() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Generic Stereo Device. </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DStereoDevice : public IGW3DStereoDeviceCallbacks
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the unique name identifying the device. </summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	the name. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual const char* get_Name() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual unsigned int get_NumberOfSupportedViews() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool get_RequiresHardwareSupport() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool get_IsSystemSupported() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	</summary>
	///
	/// <remarks>	</remarks>
	///
	/// <returns>	</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool get_IsHardwareDetected() const = 0;
};

}
