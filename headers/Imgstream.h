#ifndef C2_IMGSTREAM_H
#define C2_IMGSTREAM_H

#include <Image.h>
#include <stdint.h>
#include <stdio.h>

const int MIN_RGB = 0;
const int MAX_RGB = 255;
const int BMP_MAGIC_ID = 2;

struct bmpfile_magic
{
    unsigned char magic[BMP_MAGIC_ID];
};

struct bmpfile_header
{
    uint32_t file_size;
    uint16_t creator1;
    uint16_t creator2;
    uint32_t bmp_offset;
};

struct bmpfile_dib_info
{
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t num_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t bmp_byte_size;
    int32_t hres;
    int32_t vres;
    uint32_t num_colors;
    uint32_t num_important_colors;
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint32_t alpha_mask;
    uint32_t color_space_type;
    uint32_t color_space_endpoints[9];
    uint32_t gamma_red;
    uint32_t gamma_green;
    uint32_t gamma_blue;
};

static void imgstream_render(struct _Image* img, const char* file_dest) {
    FILE* fp;
    fopen_s(&fp, file_dest, "wb");

    if(fp != NULL) {
        struct bmpfile_magic magic = {
                .magic[0] = 'B',
                .magic[1] = 'M'
        };
        fwrite(&magic, sizeof(magic), 1, fp);

        struct bmpfile_header header = {
                .bmp_offset = sizeof(struct bmpfile_magic)
                            + sizeof(struct bmpfile_header)
                            + sizeof(struct bmpfile_dib_info),
                .file_size  = header.bmp_offset
                            + (img->res.y * 4 + img->res.x % 4)
                            + img->res.y
        };
        fwrite(&header, sizeof(header), 1, fp);

        struct bmpfile_dib_info dib_info = {
                .header_size = sizeof(struct bmpfile_dib_info),
                .width       = img->res.y,
                .height      = img->res.x,
                .num_planes  = 1,
                .bits_per_pixel = 32,
                .compression = 0x0003, //BI_BITFIELDS valid for 16/32 bit uncompressed
                .bmp_byte_size = (32*img->res.x*img->res.y)/8,
                .hres = 2835,
                .vres = 2835,
                .num_colors = 0,
                .num_important_colors = 0,
                .red_mask = 0x00ff0000,
                .green_mask = 0x0000ff00,
                .blue_mask = 0x000000ff,
                .alpha_mask = 0xff000000,
                .color_space_type = 0x73524742,  // sRGB
                .gamma_red = 0,
                .gamma_green = 0,
                .gamma_blue = 0
        };
        fwrite(&dib_info, sizeof(dib_info), 1, fp);

        for(size_t y = 0; y < img->res.y; y++) {
            for(size_t x = 0; x < img->res.x; x++) {
                pixel pxl = get_pixel((vector2u){x, y}, img);
                //RGBA
                uint8_t B = gpxl_B(&pxl), G = gpxl_G(&pxl), R = gpxl_R(&pxl), A = gpxl_A(&pxl);
                fwrite(&B, sizeof(uint8_t), 1, fp);
                fwrite(&G, sizeof(uint8_t), 1, fp);
                fwrite(&R, sizeof(uint8_t), 1, fp);
                fwrite(&A, sizeof(uint8_t), 1, fp);
//                fputc(B, fp);
//                fputc(G, fp);
//                fputc(R, fp);
//                fputc(A, fp);
            }
            for(int i = 0; i < (4 - (img->res.x * 4) % 4) % 4; i++)
                fputc(0, fp);
        }
    }

    fclose(fp);
}

static void imgstream_read(struct _Image* img, const char* file_dest) {
    FILE* fp;
    fopen_s(&fp, file_dest, "rb");

    if(fp != NULL) {
        struct bmpfile_magic magic;
        fread(&magic, sizeof(struct bmpfile_magic), 1, fp);
        if(magic.magic[0] != 'B' || magic.magic[1] != 'M') {
            exit(EXIT_FAILURE);
        }

        struct bmpfile_header header;
        fread(&header, sizeof(struct bmpfile_header), 1, fp);
        puts("-----bmpfile_header-----");
        printf("file_size: %u", header.file_size);
        printf("creator1: %hu", header.creator1);
        printf("creator2: %hu", header.creator2);
        printf("bmp_offset: %u", header.bmp_offset);

        struct bmpfile_dib_info dib_info;
        fread(&dib_info, sizeof(struct bmpfile_dib_info), 1, fp);
        puts("-----bmpfile_dib_info-----");
        printf("header_size %u", dib_info.header_size);
        printf("width %d", dib_info.width);
        printf("height %d", dib_info.height);
        printf("num_planes %hu", dib_info.num_planes);
        printf("bits_per_pixel %hu", dib_info.bits_per_pixel);
        printf("compression %u", dib_info.compression);
        printf("bmp_byte_size %u", dib_info.bmp_byte_size);
        printf("hres %d", dib_info.hres);
        printf("vres %d", dib_info.vres);
        printf("num_colors %u", dib_info.num_colors);
        printf("num_important_colors %u", dib_info.num_important_colors);
        printf("red_mask %u", dib_info.red_mask);
        printf("green mask %u", dib_info.green_mask);
        printf("blue mask %u", dib_info.blue_mask);
        printf("alpha mask %u", dib_info.alpha_mask);
        printf("gamma red %u", dib_info.gamma_red);
        printf("gamma green %u", dib_info.gamma_green);
        printf("gamma blue %u", dib_info.gamma_blue);
        if(dib_info.compression != 0) {
            exit(EXIT_FAILURE);
        }

        *img = img_create((struct _vector2sz) {dib_info.width, dib_info.height});
        for(size_t y = 0; y < dib_info.height; y++) {
            for(size_t x = 0; x < dib_info.width; x++) {
                uint8_t b = 0, g = 0, r = 0, a = 0;
//                fread(&b, sizeof(uint8_t), 1, fp);
//                fread(&g, sizeof(uint8_t), 1, fp);
//                fread(&r, sizeof(uint8_t), 1, fp);
//                fread(&a, sizeof(uint8_t), 1, fp);
                b = fgetc(fp);
                g = fgetc(fp);
                r = fgetc(fp);
                a = fgetc(fp);
                pixel pxl = pxl_create(r, g, b, a);
                if(!set_pixel((struct _vector2u) { x, y }, &pxl, img))
                    exit(EXIT_FAILURE);
            }
            fseek(fp, dib_info.width % 4, SEEK_CUR);
        }
    }

    fclose(fp);
}

#endif //C2_IMGSTREAM_H
