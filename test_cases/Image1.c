#include <Imgstream.h>

int main(void) {
    Image img = img_create((vector2sz) { 361, 867 });
    int i, j;
    for (i = 0; i < img.res.y; i++) {
        for (j = 0; j < img.res.x; j++) {
            pixel pxl = pxl_create(
                    (uint8_t) (i * 255 / img.res.y),
                    (uint8_t) (j * 255 / img.res.x),
                    (uint8_t) ((i+j) * 255 / (img.res.y/img.res.x)),
                    (uint8_t) (255)
                    );
            if(!set_pixel((vector2u) {i, j}, &pxl, &img))
                exit(EXIT_FAILURE);
        }
    }
    imgstream_render(&img, "IMG1.bmp");
}