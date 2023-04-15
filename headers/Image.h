#ifndef IMAGE_H
#define IMAGE_H

#include <stdlib.h>

#define __UNUSED_RET_WARN __attribute__((warn_unused_result))
#define __NORETURN        __attribute__((noreturn))

typedef unsigned char uint8_t;

//_vector2

#define _vector2(what, name) \
typedef struct _vector2##name { \
    what x; \
    what y; \
} vector2##name

_vector2(size_t, sz); //_vector2sz
_vector2(float, f); //_vector2f
_vector2(unsigned, u); //_vector2u

//!vector2

//pixel

typedef unsigned int  pixel;

pixel pxl_create(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    pixel color = 0;
    color |= ((pixel)r << 24);
    color |= ((pixel)g << 16);
    color |= ((pixel)b << 8);
    color |= ((pixel)a << 0);
    return color;
}

uint8_t gpxl_R(pixel* pxl) { return (*pxl >> 24) & 0xFF; }
uint8_t gpxl_G(pixel* pxl) { return (*pxl >> 16) & 0xFF; }
uint8_t gpxl_B(pixel* pxl) { return (*pxl >> 8)  & 0xFF; }
uint8_t gpxl_A(pixel* pxl) { return (*pxl >> 0)  & 0xFF; }

void __NORETURN spxl_R(uint8_t r, pixel* pxl) { *pxl |= ((pixel)r << 24); }
void __NORETURN spxl_G(uint8_t g, pixel* pxl) { *pxl |= ((pixel)g << 16); }
void __NORETURN spxl_B(uint8_t b, pixel* pxl) { *pxl |= ((pixel)b <<  8); }
void __NORETURN spxl_A(uint8_t a, pixel* pxl) { *pxl |= ((pixel)a <<  0); }

//!pixel

//image

typedef struct _Image {
    _vector2sz res;
    pixel*     arr;
} Image;

_Image img_create(_vector2sz r) {
    return (_Image) {
        .res = r,
        .arr = calloc(r.x * r.y, sizeof(pixel))
    };
}

int check_bounds(_vector2u pos, _Image* img) {
    if(img->res.x > pos.x && img->res.y > pos.y) { return 1; }
    return -1;
}

int __UNUSED_RET_WARN set_pixel(_vector2u pos, pixel* pxl, _Image* img) {
    if(check_bounds(pos, img)) {
        img->arr[pos.x*pos.y] = *pxl;
        return 1;
    }
    return -1;
}

pixel get_pixel(_vector2u pos, _Image* img) {
    if(check_bounds(pos, img)) {
        return img->arr[pos.x*pos.y];
    }
    return NULL;
}

//!image

#endif //!IMAGE_H