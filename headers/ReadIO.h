#ifndef C2_READIO_H
#define C2_READIO_H

#include <DeepMain.h>

wString READ_IO_rs(FILE* fp) {
    size_t len = 0;
    fread(&len, sizeof(size_t), 1, fp);
    char* buff = malloc(sizeof(char)*len);
    fread(&buff, sizeof(char), len, fp);
    return (wString) {
        .buff = buff
    };
}

int READ_IO_ri(FILE* fp) {
    int n = 0;
    fread(&n, sizeof(int), 1, fp);
    return n;
}

triplet READ_IO_rtr(FILE* fp) {
    triplet tr = init(0, 0, 0);
    fread(&tr, sizeof(triplet), 1, fp);
    return tr;
}

#endif //C2_READIO_H
