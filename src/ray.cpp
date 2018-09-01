#include <stdio.h>
#include <malloc.h>
#include "common.h"
#include "canvas.h"
#include "scene.h"
#include "shapes.h"
#include "material.h"
#include "bitmap.h"

#define WIDTH   1280
#define HEIGHT  720

// Initializes a Canvas
// Allocates width * height pixels
static void initCanvas(Canvas* pCanvas, const uint32 width, const uint32 height)
{
    pCanvas->pPixels = (rgba32*)malloc(width * height * sizeof(rgba32));
    pCanvas->width = width;
    pCanvas->height = height;
}

// Frees the allocated pixels of a Canvas
static void freeCanvas(Canvas* pCanvas)
{
    free(pCanvas->pPixels);
}

// Fills a Canvas with an rgba32 color
static void fillCanvas(Canvas* pCanvas, const rgba32 color)
{
    rgba32* pixel = pCanvas->pPixels;
    rgba32* last = pCanvas->pPixels + pCanvas->width * pCanvas->height;
    for( ; pixel != last; ++pixel) *pixel = color;
}

// Writes a Canvas to a Bitmap format
static void writeBitmap(Bitmap* pBitmap, const Canvas* pCanvas)
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
static bool saveBitmap(const Bitmap* pBitmap, const char* filepath)
{
    FILE* file = 0;
    bool failed = fopen_s(&file, filepath, "wb");
    if(failed) return false;

    fwrite(&pBitmap->header, sizeof(BitmapHeader), 1, file);
    fwrite(pBitmap->pData, pBitmap->dataSize, 1, file);
    fclose(file);
    
    return true;
}

// Populates the scene with arbitrary data (for now)
static void populateScene(Scene* pScene)
{
    pScene->pMaterials = (Material*)malloc(2 * sizeof(Material));
    pScene->materialCount = 2;
    pScene->pPlanes = (Plane*)malloc(1 * sizeof(Plane));
    pScene->planeCount = 1;
    pScene->pSpheres = (Sphere*)malloc(1 * sizeof(Sphere));
    pScene->sphereCount = 1;

    pScene->pMaterials[0].color = Color4f { 0.0f, 1.0f, 1.0f, 1.0f };
    pScene->pMaterials[1].color = Color4f { 1.0f, 0.0f, 0.0f, 1.0f };

    pScene->pPlanes[0].norm = Vec3f { 0.0f, 1.0f, 0.0f };
    pScene->pPlanes[0].dist = 0.0f;
    pScene->pPlanes[0].matID = 0;

    pScene->pSpheres[0].point = Vec3f { 0.0f, 0.0f, 0.0f };
    pScene->pSpheres[0].radius = 10.0f;
    pScene->pSpheres[0].matID = 1;

    #define AXIS_UP Vec3f { 0.0f, 0.0f, 1.0f }

    Camera camera {};
    camera.pos      = Vec3f { 0.0f, 10.0f, 1.0f };
    camera.forward  = normalize(camera.pos);
    camera.right    = normalize(cross(camera.forward, AXIS_UP));
    camera.up       = normalize(cross(camera.forward, camera.right));

    pScene->camera = camera;
}

// Frees all allocations from populateScene
static void freeScene(Scene* pScene)
{
    free(pScene->pMaterials);
    free(pScene->pPlanes);
    free(pScene->pSpheres);
}

// Ray-traces the full scene and stores the image in the canvas
static void render(Canvas* pCanvas, Scene* pScene)
{
    for(uint32 y = 0; y < pCanvas->height; y++)
    {
        for(uint32 x = 0; x < pCanvas->width; x++)
        {
            
        }
    }
}

int main(int argc, char const** argv)
{
    Canvas  canvas  {};
    Scene   scene   {};
    Bitmap  bitmap  {};

    initCanvas(&canvas, WIDTH, HEIGHT);
    fillCanvas(&canvas, 0xFF0000FF);

    Vec3f forward = Vec3f { 0.5f, 0.5f, 0.0f };
    Vec3f right;
    Vec3f up;

    Ray3f test = { 0, 0, 0, 0, 0, 0, 1.0f };
    
    calcCoordsLeft(forward, &right, &up);

    populateScene(&scene);

    render(&canvas, &scene);

    writeBitmap(&bitmap, &canvas);
    saveBitmap(&bitmap, "ray.bmp");

    freeScene(&scene);
    freeCanvas(&canvas);

    return 0;
}
