#pragma once
#include "common.h"
#include "vector.h"

struct Camera
{
    Vec3f pos;
    Vec3f forward;  // Relative Z-Axis
    Vec3f right;    // Relative X-Axis
    Vec3f up;       // Relative Y-Axis
};