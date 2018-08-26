#pragma once
#include "common.h"

// Stores an array of rgba32 pixels
struct Canvas
{
    rgba32*     pPixels;
    uint32      width;
    uint32      height;
};