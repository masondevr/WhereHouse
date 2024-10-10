#include <stdint.h>
#include <stdio.h>
#include <string.h>

#pragma pack(push, 1) // no padding in structss
typedef struct {
    uint16_t bfType;      // Magic number for BMP files (should be 'BM')
    uint32_t bfSize;      // Size of the BMP file in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of the info header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes (must be 1)
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;   // Compression method (0 = none)
    uint32_t biSizeImage;     // Size of image data (may be 0 for uncompressed)
    int32_t  biXPelsPerMeter; // Horizontal resolution (pixels per meter)
    int32_t  biYPelsPerMeter; // Vertical resolution (pixels per meter)
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;  // Important colors (0 = all)
} BITMAPINFOHEADER;
#pragma pack(pop)

