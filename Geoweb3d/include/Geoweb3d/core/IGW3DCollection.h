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

/*! Primary namespace */
namespace Geoweb3d
{

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	A collection. </summary>
	///
	/// <remarks>	A collection is a container of items. Items may be retrived by index, or using an
	/// 			iterator. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	template<typename T>
	struct IGW3DCollection
	{
	public:
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Gets the count. </summary>
		///
		/// <remarks>	Gets the number of items in the collection. </remarks>
		///
		/// <returns>	the count. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual unsigned long count() const = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Increment the iterator to the next item. </summary>
		///
		/// <param name="ppVal">	[out] Pointer to the next item. Note you must pass in a real object by
		/// 						reference, not a null pointer.
		/// 						</param>
		///
		/// <returns>	true if it succeeds, false if it fails (i.e. the iterator reached the end). </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool next(T* ppVal) = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Reset the iterator back to the first item. </summary>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual void reset() = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Retrieve the item at the given index. </summary>
		///
		/// <param name="index">	Zero-based index of the item. </param>
		///
		/// <returns>	The item. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual		  T operator[](unsigned long index) = 0;

		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Retrieve the item at the given index. </summary>
		///
		/// <param name="index">	Zero-based index of the item. </param>
		///
		/// <returns>	The item. </returns>
		////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual       T get_AtIndex(unsigned long index) = 0;
	};

}