#include <stdio.h>
#include <malloc.h>
#include "common.h"
#include "canvas.h"
#include "bitmap.h"

#define WIDTH   1280
#define HEIGHT  720

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
    rgba32* pixel = pCanvas->pPixels;
    rgba32* last = pCanvas->pPixels + pCanvas->width * pCanvas->height;
    for( ; pixel != last; ++pixel) *pixel = color;
}

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
