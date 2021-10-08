/**
 * Property of Geoweb3d Inc.
 * --------------------------------
 * Copyright 2008-2011
 * Author: Vincent A. Autieri, Geoweb3d
 * Geoweb3d source code is not free software: you cannot distribute,
 * redistribute, and/or modify it under any terms.
 **/

#pragma once

#include "../../core/GW3DInterFace.h"
namespace Geoweb3d
{
//here an not in the interface..as this is not implimented stuff..
struct	IGW3DNode;
_GW3D_SMARTPTR_TYPEDEF( IGW3DNode );

//nodes can have state, as well as children (IGW3DSpatialCollection) that have state as well.
//being smart about how you are changing (or not changing) states can make or break performance
//example would be, is if you add children, add them all under the same node with the same state(best case), OR
//make all the children have the same state(second best case).  If you add a node, set color, add another node,
//set to a different color, then add a 3rd node that was the same state as the 1st node, you are not optimized
//and will always be uploading state information to the GPU instead of just focusing on rendering....


//NOTE You are not involved in the actual traversal of the Scenegraph, as all you are doing is building up
//an in memory "model" that the SDK can load from memory (instead of off disk for example).
struct IGW3DNode : public IGW3DSpatial
{
    virtual IGW3DSpatialCollection * get_SpatialCollection() = 0;
} ;
}


