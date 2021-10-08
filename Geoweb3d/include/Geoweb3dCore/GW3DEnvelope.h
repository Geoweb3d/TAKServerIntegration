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
* @file GW3DEnvelope.h
*
* Envelope Classe
*/

/*! Primary namespace */
namespace Geoweb3d
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	An envelope. </summary>
	///
	/// <remarks>	An envelope is a simple container for a bounding area. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	class GEOWEB3DENGINE_API GW3DEnvelope
	{
	public:

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Default constructor. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		GW3DEnvelope();

		bool operator==(const GW3DEnvelope& p) const
		{
			//note, to make a robust compare, probably should
			//use a tolerance

			if (MinX != p.MinX)
				return false;

			if (MaxX != p.MaxX)
				return false;

			if (MinY != p.MinY)
				return false;

			if (MaxY != p.MaxY)
				return false;

			if (MinZ != p.MinZ)
				return false;

			if (MaxZ != p.MaxZ)
				return false;

			return true;
		}

		GW3DEnvelope& operator=(GW3DEnvelope const& rhs)
		{
			MinX = rhs.MinX;
			MaxX = rhs.MaxX;
			MinY = rhs.MinY;
			MaxY = rhs.MaxY;
			MinZ = rhs.MinZ;
			MaxZ = rhs.MaxZ;

			return *this;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Checks if the envelope is null. </summary>
		///
		/// <remarks>	An envelope is null if all its edges are at 0.0.  This is the envelope's default 
		/// 			state on construction, therefore if an envelope has never been set, it is null. 
		/// 			</remarks>
		///
		/// <returns>	true if null, false if not null. </returns>
		/// 
		/// <see cref="reset"/>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool get_IsNull() const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Merges a coordinate into the envelope. </summary>
		///
		/// <remarks>	Expands the existing envelope dimensions to include the coordinate provided. 
		/// 			</remarks>
		///
		/// <param name="dfX">	The x coordinate. </param>
		/// <param name="dfY">	The y coordinate. </param>
		/// <param name="dfZ">	The z coordinate. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void merge(double dfX, double dfY, double dfZ);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Merges another envelope. </summary>
		///
		/// <remarks>	Expands to existing envelope dimensions to completely include the dimensions of 
		/// 			sOther. If this envelope is null, it will be set to the exact dimenions of sOther.
		/// 			</remarks>
		///
		/// <param name="sOther">	The other envelope. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void merge(GW3DEnvelope const& sOther);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Intersects another envelope. </summary>
		///
		/// <remarks>	Reduces the existing envelope dimensions to only include the area or volume shared 
		/// 			both envelopes (i.e. where they overlap). If this envelope is null, it will be set 
		/// 			to the exact dimenions of sOther.</remarks>
		///
		/// <param name="sOther">	The other. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void intersect(GW3DEnvelope const& sOther);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this envelope intersects the given other. </summary>
		///
		/// <param name="other">	The other. </param>
		///
		/// <returns>	true if it succeeds, false if it fails. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool intersects(GW3DEnvelope const& other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Query if this envelope contains the given other. </summary>
		///
		/// <param name="other">	Tests the envelope to determine if the other envelope is completely 
		/// 						contained by this envelope. </param>
		///
		/// <returns>	true if the other envelope is contained by this envelope, false if not. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		bool contains(GW3DEnvelope const& other) const;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Sets the dimensions of the envelope. </summary>
		///
		/// <param name="MinX">	The minimum x coordinate. </param>
		/// <param name="MaxX">	The maximum x coordinate. </param>
		/// <param name="MinY">	The minimum y coordinate. </param>
		/// <param name="MaxY">	The maximum y coordinate. </param>
		/// <param name="MinZ">	The minimum z coordinate. </param>
		/// <param name="MaxZ">	The maximum z coordinate. </param>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void put(
			const double& MinX, const double& MaxX,
			const double& MinY, const double& MaxY,
			const double& MinZ, const double& MaxZ);

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Resets this envelope to null. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		void reset();
		/// <summary>	The minimum x coordinate. </summary>
		double      MinX;
		/// <summary>	The maximum x coordinate. </summary>
		double      MaxX;
		/// <summary>	The minimum y coordinate. </summary>
		double      MinY;
		/// <summary>	The maximum y coordinate. </summary>
		double      MaxY;
		/// <summary>	The minimum z coordinate. </summary>
		double      MinZ;
		/// <summary>	The maximum z coordinate. </summary>
		double      MaxZ;
	};
};