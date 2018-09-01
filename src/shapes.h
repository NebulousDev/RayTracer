#pragma once
#include "common.h"
#include "vector.h"

struct Plane
{
    Vec3f   norm;
    float32 dist;
    uint32  matID;
};

struct Sphere
{
    Vec3f   point;
    float32 radius;
    uint32  matID;
};