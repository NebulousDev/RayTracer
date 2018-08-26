#pragma once
#include "common.h"

// File header for the Bitmap filetype
#pragma pack(push, 1)
struct BitmapHeader
{
    uint16  type;           //  2 bytes     File type (0x4D42 "BM")
    uint32  filesize;       //  4 bytes     Size of full file
    uint16  reserved1;      //  2 bytes     Not used
    uint16  reserved2;      //  2 bytes     Not used
    uint32  offset;         //  4 bytes     Header offset size (14)
    uint32  size;           //  4 bytes     Size of BMP header
    uint32  width;          //  4 bytes     Image width
    uint32  height;         //  4 bytes     Image height
    uint16  planes;         //  2 bytes     Idk, set to 1
    uint16  bits;           //  2 bytes     Number of bits per pixel
    uint32  compression;    //  4 bytes     Compression type (0 = Bi_RGB)
    uint32  bitmapSize;     //  4 bytes     Number of pixels
    uint32  horizontal;     //  4 bytes     Not used
    uint32  vertical;       //  4 bytes     Not used
    uint32  colors;         //  4 bytes     Not used
    uint32  important;      //  4 bytes     Not used
    //uint32  redMask;      //  4 bytes     0xFF000000
    //uint32  greenMask;    //  4 bytes     0x00FF0000
    //uint32  blueMask;     //  4 bytes     0x0000FF00
};
#pragma pack(pop)

// Bitmap file header and data
struct Bitmap
{
    BitmapHeader    header;
    rgba32*         pData;
    uint32          dataSize;
};