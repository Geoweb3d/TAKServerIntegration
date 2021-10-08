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
#include "../core/IGW3DCollection.h"
#include "../../Geoweb3dCore/GeometryExports.h"
#include "GW3DExports.h"
namespace Geoweb3d
{
////////////////////////////////////////////////////////////////////////////////////////////////////
// namespace: Vector
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Vector
{
////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Optional callback when representing a vector layer </summary>
///
/// <remarks>	Optional callback type used in RepresentFileParams for ignoring/accepting features
/// 			for visualization. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DConstructionCallbackRepresentationSettings
{
	const IGW3DPropertyCollection *representation_properties;
	virtual bool put_VectorRepresentationProperty( unsigned property_index, const IGW3DVariant &value ) = 0;
};

struct IGW3DConstructionCallback
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Explicit constructor to allow control over unique property use.  </summary>
	/// <param name="always_use_unique_props_if_available"> When true, allows for unique properties to
	/// be set via other api functions for rendering (i.e. streaming). While still allowing onInsert to
	/// be used for simple feature filtering. Should be set to false when setting properties via
	/// onInsert </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	IGW3DConstructionCallback( bool always_use_unique_props_if_available = false )
	{}

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Values that represent ConstructionCallbackReturnType. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    enum ConstructionCallbackReturnType
    {
        /// Ignore this feature in visualization
        DISCARD = 0,
        /// Keep this feature for visualization. 
        KEEP	= 1, 
		/// Keep this feature for visualization and persist it's representation properties
		KEEP_AND_SAVE = 2
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Executes the insert action. </summary>
    ///
    /// <remarks>	This callback function is called on construction of the representation, and
    /// 			alows the developer to filter the features that are rendered as part of the
    /// 			representation. </remarks>
    ///
    /// <param name="feature_id">		 	Identifier for the feature. </param>
    /// <param name="feature_attributes">	The feature's attributes. </param>
    ///
    /// <returns>	Return DISCARD to exclude the feature, or KEEP to include it. </returns>
    ///
	// Notes: representation_properties in IGW3DConstructionCallbackRepresentationSettings will be the default representation properties and is here to ensure you are 
	// talking in a threadsafe way.  Do not call other APIs of the SDK as it will be at your own risk if you do.  This callback is not in the main application thread.
	// With that said, we only allow 1 thread in here at a time so you are safe in that regard. Calling put_VectorRepresentationProperty in IGW3DConstructionCallbackRepresentationSettings 
	// will force a clone of the current representation properties in a thread safe way, giving this feature unique rep properties.  However, this features configuration is not
	// saved as if set via the other SDK API(s).  In fact, if you have a unique configuration for this feature already set, it will be used no matter what you do here as that will 
	// take priority over this. This API is for streamlined attribute mapping for extremely large datasets and/or blazing speed where you want most feature to be configured
	// algorithmically every time it is about to get inserted into the 3d scene
	/// <see cref="RepresentationLayerCreationParameter"/>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual ConstructionCallbackReturnType onInsert( long feature_id, const IGW3DPropertyCollection *feature_attributes, IGW3DConstructionCallbackRepresentationSettings *representation_properties ) = 0;

	virtual void onRemove(long feature_id) {};

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Standard Paging Policy. </summary>
///
/// <remarks>  This is the standard paging policy object used in the creation of a representation. 
///            Vector layers will be paged in based on their bounds and which page level they are
///            set to page in. </remarks>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DPagingPolicy
{
	virtual ~IGW3DPagingPolicy() {};

	IGW3DPagingPolicy(){}

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Vector Layer Assisted Paging Policy. </summary>
///
/// <remarks>  This extends the behaviors of the standard paging policy by additionally using
///            the envelope information of each feature to assist in deciding when a feature should be paged
///            into the system.  If the weak pointer is expired the layer used for envelope information paging will be 
///			   the layer being represented. </remarks>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DVectorLayerAssistedPagingPolicy : public IGW3DPagingPolicy
{

	IGW3DVectorLayerWPtr layer; 

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	LOD Paging Policy. </summary>
///
/// <remarks>	This extends the behaviors of the standard paging policy by additionally using
///				a oage kevel range.  This object is only taken into account for datasources that
///				can be auto represented. (i.e. CDB).  Auto representing is valid for datasources that
///				already have an implicit LOD type structure.  page_level_start is the same concept
///				used in our standard representation (see - RepresentationLayerCreationParameter). The 
///				page_level_end is a way to control how the LOD structure of the datasource will map to 
///				our internal LOD system. 
///
///				Ranges from 1 - 17 unless other low level configurations have taken place.
/// 			Lower numbers bringing in the dataset further away, thus memory footprints
/// 			will increase as well as performance decreasing.  
///				 </remarks>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DLODPagingPolicy : public Vector::IGW3DPagingPolicy
{
	unsigned page_level_start;
	//unsigned page_level_end;  Currently defined as page_level_start + 23 for CBD

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Representation layer creation parameter. </summary>
///
/// <remarks>	Defines parameters of a new representation.  It is more efficient
/// 			to define these parameters on construction rather than setting them afterward.
/// 			</remarks>
///
/// <see cref="IGW3DVectorRepresentationCollection::create"/>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct RepresentationLayerCreationParameter
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Default constructor. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    RepresentationLayerCreationParameter() :
        cb( 0 ),
        page_level( 11 ),
        representation_layer_activity(true),
		use_spatial_filter(false)
    { }

	/// <summary>	A function to ignore/keep features for visualization with the ConstructionCallback signature. </summary>
	IGW3DConstructionCallback *cb;

    /// <summary>	true to use spatial filter, restricting the representation to the envelope spatial_filter_bounds. </summary>
    bool use_spatial_filter;

    /// <summary>	The spatial filter bounds, in WGS84 Geodetic.  Set use_spatial_filter to true to use</summary>
    GW3DEnvelope spatial_filter_bounds;

	/// <summary>	The page level. A distance ID to start bringing in the file. </summary>
	///
	/// <remarks>	Ranges from 1 - 17 unless other low level configurations have taken place.
	/// 			Lower numbers bringing in the dataset further away, thus memory footprints
	/// 			will increase as well as performance decreasing.  This value range depends
	/// 			on other values internal to the SDK.</remarks>
	unsigned page_level;

    /// <summary>	true to have representation active on construction. </summary>
    bool representation_layer_activity;

    /// <summary>	Options for controlling the representation default properties. </summary>
	/// <remarks>	Internally will call SetRepresentationLayerDefaultProperties
	/// 			with these values. Note, its best to clone the global
	/// 			properties first (from the representation driver), and then
	/// 			set the properties from it.  This way if a new property is added
	/// 			in a future version of Geoweb3d, you are ensured to be compatible.
	///				If this is not set, the global settings for this representation
	///				will be used. </remarks>
    IGW3DPropertyCollectionPtr representation_default_parameters;

	/// <summary>	If a layer supports field grouping, you can set this handle. </summary>
	IGW3DVectorLayerFieldFilterPtr field_filter;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sets the image palette to be used in this representation. </summary>
    ///
    /// <remarks>	The images defined in the token will be used as a palette, where the properties that
    /// 			use it will reference the palette images using the index of the image within the
    /// 			image collection that created it.  Note that changes to the image collection after
    /// 			this finalization token was generated do not affect the representation.  Any
    /// 			existing palette will be overwritten.  Undefined results if you have  feature/object
    /// 			ids mapped outside of a palette's maximum index. </remarks>
    ///
    /// <param name="images">	The image finalization token. </param>
    ///
    /// <returns> </returns>
    ///
    /// <see cref="IGW3DImageCollection::create_FinalizeToken"/>
	/// <see cref="IGW3DVectorRepresentation::put_GW3DFinalizationToken"/>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

	IGW3DTokenPtr finalization_token;
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A vector representation collection. </summary>
///
/// <remarks>	The collection of vector representations for a single representation driver. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DVectorRepresentationCollection : public IGW3DCollection< IGW3DVectorRepresentationWPtr >
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Array indexer operator. </summary>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual const IGW3DVectorRepresentationWPtr operator[](  unsigned long index ) const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets representation at the given index. </summary>
    ///
    /// <param name="index">	Zero-based index of the representation. </param>
    ///
    /// <returns>	the index. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual const IGW3DVectorRepresentationWPtr get_AtIndex( unsigned long index ) const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Creates a vector representation for the given vector layer. </summary>
    ///
    /// <remarks>	Creates a vector representation for the given vector layer, using the representation
    /// 			driver that this collection belongs to. </remarks>
    ///
    /// <param name="layer"> 	The layer. </param>
    /// <param name="params">	Options for the new representation. </param>
    ///
    /// <returns>	The new representation. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual IGW3DVectorRepresentationWPtr create( IGW3DVectorLayerWPtr layer, const Vector::RepresentationLayerCreationParameter  &params  ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Creates a vector representation for the given vector layer with advanced paging configurations. </summary>
    ///
    /// <remarks>	Creates a vector representation for the given vector layer, using the representation
    /// 			driver that this collection belongs to and a page policy object.  </remarks>
    ///
    /// <param name="layer"> 	The layer. </param>
    /// <param name="params">	Options for the new representation. </param>
	/// <param name="page_policy_">	Page policy object for advanced paging configurations.</param>
    ///
    /// <returns>	The new representation. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual IGW3DVectorRepresentationWPtr create(IGW3DVectorLayerWPtr layer, const Vector::RepresentationLayerCreationParameter  &params , const Vector::IGW3DPagingPolicy* page_policy_) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Closes the given representation. </summary>
    ///
    /// <remarks>	Closes the given representation and removes it from the collection.
    ///
    /// 			To close a representation: IGW3DVectorRepresentationCollection::close( rep );
    ///
    ///				IGW3DVectorRepresentationWPtr will become expired.</remarks>
    ///
    /// <param name="rep">	[in] The representation. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    static void close( IGW3DVectorRepresentationWPtr &rep  )
    {
        close_VectorRepresentation( rep );
    }
};
}
