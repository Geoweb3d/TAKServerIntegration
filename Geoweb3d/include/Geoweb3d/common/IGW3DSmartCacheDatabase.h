//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2017, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// Geoweb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../core/GW3DInterFace.h"

/*! Primary namespace */
namespace Geoweb3d
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> </summary>
///
/// <remarks></remarks>
///
/// <see cref="IGW3DSmartCacheScopedRecord"/>
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DSmartCacheScopedRecord
{
	virtual ~IGW3DSmartCacheScopedRecord()
	{}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Cancels the record and gives it back to the IGW3DSmartCacheDatabase </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void put_Canceled() = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Replaces this record's contents with the given user data </summary>
	/// 
	/// <param name="data"> the user data to give to the record </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void put_UserData( Geoweb3d::IGW3DClientUserDataPtr data ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Accesses this record's held user data. </summary>
	/// <returns> the user data held by this record </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual Geoweb3d::IGW3DClientUserDataPtr get_UserData() const = 0;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> </summary>
///
/// <remarks></remarks>
///
/// <see cref="IGW3DSmartCacheDatabase"/>
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DSmartCacheDatabase
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the record for the given unique and global key pair. </summary>
	/// 
	/// <remarks> Will Reserve space if necessary </remarks>
	/// 
	/// <param name="unique_key"> the record's unique key </param>
	/// <param name="associated_key_to_unique"> the record's global key </param>
	/// <returns> an IGW3DSmartCacheScopedRecordPtr </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual Geoweb3d::IGW3DSmartCacheScopedRecordPtr get_Record(int64_t unique_key, int64_t associated_key_to_unique ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Finds the record for the given unique and global key pair. </summary>
	/// 
	/// <param name="unique_key"> the record's unique key </param>
	/// <returns> if the record is found a valid IGW3DSmartCacheScopedRecordPtr is returned </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual Geoweb3d::IGW3DSmartCacheScopedRecordPtr find_Record(int64_t unique_key ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> releases the record for the given unique and global key pair. </summary>
	/// 
	/// <param name="unique_key"> the record's unique key </param>
	/// <param name="associated_key_to_unique"> the record's global key </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void release_Record(int64_t unique_key, int64_t associated_key_to_unique ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> releases all records for the given global key. </summary>
	/// 
	/// <param name="associated_key_to_unique"> the record's global key </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void release_AssociatedRecords(int64_t associated_key_to_unique ) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary> Gets the number of records currently in the cache  </summary>
	/// 
	/// <returns> the number of records currently in the cache </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual int64_t get_RecordCount() const = 0;
};

}
