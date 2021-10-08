#pragma once

//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2019, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

/**
* @file GW3DGeometry.h
*
* GW3DGeometry Classes
*/

#include "Geoweb3dExports.h"
#include "GW3DResults.h"
#include "GW3DEnvelope.h"

/*! Primary namespace */
namespace Geoweb3d
{
	class GW3DPoint;
	class GW3DLinearRing;
	class GW3DLineString;
	class GW3DPolygon;
	class GW3DMultiPoint;
	class GW3DMultiLineString;
	class GW3DMultiPolygon;
	class GW3DCurve;
	class GW3DCompoundCurve;
	class GW3DCurvePolygon;
	class GW3DMultiCurve;
	class GW3DBaseImpl;
	class GW3DPointImpl;
	class GW3DPolygonImpl;
	class GW3DLineStringImpl;
	class GW3DLinearRingImpl;
	class GW3DMultiPolygonImpl;
	class GW3DMultiPointImpl;
	class GW3DMultiLineStringImpl;
	class GW3DSphereImpl;
	class GW3DRayImpl;
	class GW3DCurveImpl;
	class GW3DCompoundCurveImpl;

	typedef int     GW3DBoolean;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The geometry visitor virtual baseclass. </summary>
	///
	/// <remarks>	This is the pure virtual base class for easy access to the underlying geometry type
	/// 			 </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	class GEOWEB3DENGINE_API IGW3DGeometryVisitor
	{
	public:
		// Visit GW3DPoint. 
		virtual void visit(GW3DPoint*) = 0;
		// Visit GW3DLineString. 
		virtual void visit(GW3DLineString*) = 0;
		// Visit GW3DLinearRing. 
		virtual void visit(GW3DLinearRing*) = 0;
		// Visit GW3DPolygon. 
		virtual void visit(GW3DPolygon*) = 0;
		// Visit GW3DMultiPoint. 
		virtual void visit(GW3DMultiPoint*) = 0;
		// Visit GW3DMultiLineString. 
		virtual void visit(GW3DMultiLineString*) = 0;
		// Visit GW3DMultiPolygon. 
		virtual void visit(GW3DMultiPolygon*) = 0;
		/// Visit GW3DGeometryCollection. 
		//virtual void visit(GW3DGeometryCollection*) = 0;
		// Visit GW3DCircularString. 
		//virtual void visit(GW3DCircularString*) = 0;
		// Visit GW3DCompoundCurve. 
		//virtual void visit(GW3DCompoundCurve*) = 0;
		// Visit GW3DCurvePolygon. 
		//virtual void visit(GW3DCurvePolygon*) = 0;
		// Visit GW3DMultiCurve. 
		//virtual void visit(GW3DMultiCurve*) = 0;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The const geometry visitor virtual baseclass. </summary>
	///
	/// <remarks>	This is the pure virtual base class for easy access to the underlying geometry type
	/// 			 </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	class GEOWEB3DENGINE_API IGW3DConstGeometryVisitor
	{
	public:
		// Visit GW3DPoint. 
		virtual void visit(const GW3DPoint*) = 0;
		// Visit GW3DLineString. 
		virtual void visit(const GW3DLineString*) = 0;
		// Visit GW3DLinearRing. 
		virtual void visit(const GW3DLinearRing*) = 0;
		// Visit GW3DPolygon. 
		virtual void visit(const GW3DPolygon*) = 0;
		// Visit GW3DMultiPoint. 
		virtual void visit(const GW3DMultiPoint*) = 0;
		// Visit GW3DMultiLineString. 
		virtual void visit(const GW3DMultiLineString*) = 0;
		// Visit GW3DMultiPolygon. 
		virtual void visit(const GW3DMultiPolygon*) = 0;
		/// Visit GW3DGeometryCollection. 
		//virtual void visit(const GW3DGeometryCollection*) = 0;
		// Visit GW3DCircularString. 
		//virtual void visit(const GW3DCircularString*) = 0;
		// Visit GW3DCompoundCurve. 
		//virtual void visit(const GW3DCompoundCurve*) = 0;
		// Visit GW3DCurvePolygon. 
		//virtual void visit(const GW3DCurvePolygon*) = 0;
		// Visit GW3DMultiCurve. 
		//virtual void visit(const GW3DMultiCurve*) = 0;
		// Visit GW3DMultiSurface. 
		//virtual void visit(const GW3DMultiSurface*) = 0;
		// Visit GW3DTriangle. 
		//virtual void visit(const GW3DTriangle*) = 0;
		// Visit GW3DPolyhedralSurface. 
		//virtual void visit(const GW3DPolyhedralSurface*) = 0;
		// Visit GW3DTriangulatedSurface. 
		//virtual void visit(const GW3DTriangulatedSurface*) = 0;
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The geometry base class. </summary>
	///
	/// <remarks>	This is the base class for all geometry objects (not including GW3DEnvelope).
	/// 			 </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	class GEOWEB3DENGINE_API GW3DGeometry
	{
	public:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Default constructor. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GW3DGeometry() {};

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Destructor. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual     ~GW3DGeometry() {};

		//SKIP-CODE-BEGIN
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Object allocation operator. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void* operator new(size_t);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Object de-allocation operator. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void operator delete(void*);
		//SKIP-CODE-END

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets the dimension of the geometry. </summary>
		///
		/// <remarks>	Returns the inherent dimension of the geometry (0 for points, 1 for lines, 2 for 
		/// 			polygons). </remarks>
		///
		/// <returns>	The dimension. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual int get_Dimension() const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if the geometry is empty. </summary>
		///
		/// <remarks>	Normally this returns false, except when an object is instantiated and geometry has 
		/// 			not been assigned </remarks>
		///
		/// <returns>	True if there is no geometry, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual GW3DBoolean  get_IsEmpty() const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Makes a deep copy of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	A copy of this object. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual GW3DGeometry* clone() const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets the geometry type. </summary>
		///
		/// <returns>	The geometry type. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual GeometryType get_GeometryType() const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets the envelope of the geometry. </summary>
		///
		/// <remarks>	Computes and returns the bounding envelope for this geometry. </remarks>
		///
		/// <param name="psEnvelope">	An envelope to be set to this geometry's envelope. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual void get_Envelope(GW3DEnvelope* psEnvelope) const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object is valid. </summary>
		///
		/// <returns>	true if valid, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool get_IsValid() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets the coordinate dimension. </summary>
		///
		/// <remarks>	Gets the dimension of the coordinates in this geometry. Returns 2 for 2D or 3 for 
		/// 			3D, or 0 for an empty point geometry.</remarks>
		///
		/// <returns>	The coordinate dimension. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual int get_CoordinateDimension() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object intersects the given other. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if the geometries intersect, otherwise false. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool intersects(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Tests if this geometry is considered equal to another. </summary>
		///
		/// <param name="other">	The geometry to compare to this object. </param>
		///
		/// <returns>	true if the objects are considered equal, false if they are not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool equals(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object and the given other are disjoint. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if disjoint, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool disjoint(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object and the given other are touching. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if touching, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool touches(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object and the given other are crossing. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if crossing, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool crosses(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object is within the given other. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if within the other, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool within(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object contains the given other. </summary>
		///
		/// <param name="other">	Tests if the other geometry is completely contained by this geometry.  
		/// 						</param>
		///
		/// <returns>	true if the object contains the other, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool contains(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this object overlaps the given other. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if overlapping, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool  overlaps(const GW3DGeometry* other) const;


		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Compute distance between two geometries. </summary>
		///
		/// <remarks>	Returns the shortest distance between the two geometries. The distance is expressed 
		/// 			in the same unit as the coordinates of the geometries. To calculate the distance
		/// 			between two points in meters, consider using get_DistanceInMeters.</remarks>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	The distance. </returns>
		/// 
		/// <see cref="get_DistanceInMeters"/>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual double distance(const GW3DGeometry* other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	accept the visitor </summary>
		///
		/// <param name="IGW3DGeometryVisitor">	</param>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual void accept(IGW3DGeometryVisitor* visitor) = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	accept the const visitor </summary>
		///
		/// <param name="IGW3DGeometryVisitor">	</param>
		///
		////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual void accept(IGW3DConstGeometryVisitor* visitor) const = 0;


		// has a Z component. 
		bool  is_3D() const;
		//has a M component.
		bool  is_Measured() const;

		//SKIP-CODE-BEGIN

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	convex hull of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

	   // virtual GW3DGeometry *convex_hull() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	buffer region of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *buffer_region( const double &distance, int quadsegments = 30 ) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	intersection of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *intersection( const GW3DGeometry *) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	onvexhull of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *union_geometry( const GW3DGeometry * ) const;
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	onvexhull of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *union_cascaded() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	onvexhull of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *difference( const GW3DGeometry * ) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	onvexhull of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *sym_difference( const GW3DGeometry * ) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	centroid of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DResult    centroid( GW3DPoint &poPoint ) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	simplify of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *simplify(const double &tolerance) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	simplify_preserve_topology of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *simplify_preserve_topology(const double &tolerance) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	polygonize of this object. </summary>
		///
		/// <remarks>	Note: The returned object should be deleted when no longer needed, to prevent memory 
		/// 			leak. </remarks>
		///
		/// <returns>	null return if failed. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		//virtual GW3DGeometry *polygonize() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	import from a well known binary source. </summary>
		///
		/// <param name="binary_buffer"> the raw well known binary buffer. </param>
		/// <param name="size"> the size of the well known binary buffer. </param>
		///
		/// <returns>	GW3D_sOk if succeeded. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		virtual GW3DResult import_FromWkb(const unsigned char* binary_bin, int size);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	import from a well known text source. </summary>
		///
		/// <param name="text_buffer"> the raw well known text buffer. </param>
		///
		/// <returns>	GW3D_sOk if succeeded. </returns>
		//////////////////////////////////////////////////////////////////////////////////////////////////

		virtual GW3DResult import_FromWkt(const char** text_buffer);

		//SKIP-CODE-END

		   //internal use only.  Do not use.
		virtual const GW3DBaseImpl* getBaseImpl() const = 0;
		//internal use only.  Do not use.
		virtual GW3DBaseImpl* getBaseImpl() = 0;
	private:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Copy constructor. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GW3DGeometry(const GW3DGeometry& rhs);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Assignment operator. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GW3DGeometry& operator=(const GW3DGeometry& rhs);
	};

};