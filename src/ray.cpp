#include <stdio.h>
#include <malloc.h>

#define WIDTH   1280
#define HEIGHT  720

#define internal static

/* Typedefs */
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long int   uint64;
typedef uint32              rgba32;

// Stores an array of rgba32 pixels
struct Canvas
{
    rgba32*     pPixels;
    uint32      width;
    uint32      height;
};

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

// Writes a Canvas to a Bitmap format
internal void writeBitmap(Bitmap* pBitmap, const Canvas* pCanvas)
{
    uint32 pixelCount = pCanvas->width * pCanvas->height;
    BitmapHeader* header = &pBitmap->header;
    
    header->type            = 0x4D42;
    header->filesize        = sizeof(BitmapHeader) + pixelCount;
    header->offset          = sizeof(BitmapHeader);
    header->size            = sizeof(BitmapHeader) - 14;
    header->width           = pCanvas->width;
    header->height          = pCanvas->height;
    header->planes          = 1;
    header->bits            = 32;
    header->compression     = 0;
    header->bitmapSize      = pixelCount;
    //header->redMask       = 0xFF000000;
    //header->greenMask     = 0x00FF0000;
    //header->blueMask      = 0x0000FF00;

    pBitmap->pData          = pCanvas->pPixels;
    pBitmap->dataSize       = pixelCount * sizeof(rgba32);
}

// Saves a Bitmap to file
// Returns false if file could not be written
internal bool saveBitmap(const Bitmap* pBitmap, const char* filepath)
{
    FILE* file = 0;
    bool failed = fopen_s(&file, filepath, "wb");
    if(failed) return false;

    fwrite(&pBitmap->header, sizeof(BitmapHeader), 1, file);
    fwrite(pBitmap->pData, pBitmap->dataSize, 1, file);
    fclose(file);
    
    return true;
}

// Initializes a Canvas
// Allocates width * height pixels
internal void initCanvas(Canvas* pCanvas, const uint32 width, const uint32 height)
{
    pCanvas->pPixels = (rgba32*)malloc(width * height * sizeof(rgba32));
    pCanvas->width = width;
    pCanvas->height = height;
}

// Frees the allocated pixels of a Canvas
internal void freeCanvas(Canvas* pCanvas)
{
    free(pCanvas->pPixels);
}

// Fills a Canvas with an rgba32 color
internal void fillCanvas(Canvas* pCanvas, const rgba32 color)
{
    for(uint32 y = 0; y < pCanvas->height; ++y)
        for(uint32 x = 0; x < pCanvas->width; ++x)
            pCanvas->pPixels[x + y * pCanvas->width] = color;
}

int main(int argc, char const** argv)
{
    Canvas canvas{};
    Bitmap bitmap{};

    initCanvas(&canvas, WIDTH, HEIGHT);
    fillCanvas(&canvas, 0xFF0000FF);

    writeBitmap(&bitmap, &canvas);
    saveBitmap(&bitmap, "ray.bmp");

    freeCanvas(&canvas);

    return 0;
}
