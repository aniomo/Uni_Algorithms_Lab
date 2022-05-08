#ifndef ppm_img_h
#define ppm_img_h

#include <stdio.h>
#include <stdlib.h>

// Can also be used to store a particular colour.
typedef struct pixel
{
    unsigned char c[4];
}pixel;

typedef struct image
{
    int height, width;
    pixel** buffer;
}image;

image* create_image(int height, int width)
{
    image* newImg = (image*)malloc(sizeof(image));
    newImg->height = height;
    newImg->width = width;
    newImg->buffer = (pixel**)malloc(sizeof(pixel*) * height);
    for(int i = 0; i < height; i++)
        newImg->buffer[i] = (pixel*)malloc(sizeof(pixel) * width);
    return newImg;
}


// The running time is height*width*4
void colour_image(image* img, pixel* colour)
{
    for(int i = 0; i < img->height; i++)
    {
        for(int j = 0; j < img->width; j++)
        {
            for(int k = 0; k < 4; k++)
                img->buffer[i][j].c[k] = colour->c[k];
        }
    }
}

void print_image(image* img)
{
    //std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    printf("P3\n%d %d\n255\n", img->width, img->height);
    for(int i = 0; i < img->height; i++)
    {
        for(int j = 0; j < img->width; j++)
        {
            printf("%d %d %d\n", img->buffer[i][j].c[0], img->buffer[i][j].c[1], img->buffer[i][j].c[2]);
        }
    }
}

void generate_image(image* img, const char* filename)
{
    FILE* fptr = fopen(filename, "w");
    if(fptr == NULL)
    {
        printf("GENERATE_IMAGE_ERROR: Coudn't find file, \"%s\" ", filename);
        return;
    }
    fprintf(fptr, "P3\n%d %d\n255\n", img->width, img->height);
    for(int i = 0; i < img->height; i++)
    {
        for(int j = 0; j < img->width; j++)
        {
            fprintf(fptr, "%d %d %d\n", img->buffer[i][j].c[0], img->buffer[i][j].c[1], img->buffer[i][j].c[2]);
        }
    }
    fclose(fptr);
}

void bresenham(image* img, int* a, int* b)
{
    int dx = b[0] - a[0];
    int dy = b[1] - a[1];
    
    int xsign;
    if (dx > 0)
        xsign = 1;
    else
        xsign = -1;
    
    int ysign;
    if (dy > 0)
        ysign = 1;
    else
        ysign = -1;
    
    dx = abs(dx);
    dy = abs(dy);
    
    int temp, xx, xy, yx, yy;
    if (dx > dy)
    {
        xx = xsign;
        xy = 0;
        yx = 0;
        yy = ysign;
    }
    else
    {
        temp = dx;
        dx = dy;
        dy = temp;
        xx = 0;
        xy = ysign;
        yx = xsign;
        yy = 0;
    }
        
    int D = 2*dy - dx;
    int y = 0;
    
    pixel* white = (pixel*)malloc(sizeof(pixel));
    white->c[0] = 255;
    white->c[1] = 255;
    white->c[2] = 255;
    
    for (int x = 0; x <= dx + 1; x++)
    {
        for(int k = 0; k < 4; k++)
        {
            img->buffer[(a[1] + x*xy + y*yy)][(a[0] + x*xx + y*yx)].c[k] = white->c[k];
        }
        if (D >= 0)
        {
            y += 1;
            D -= 2*dx;
        }
        D += 2*dy;
    }
    return;
}

#endif /* ppm_img_h */
