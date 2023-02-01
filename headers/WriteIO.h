#ifndef C2_WRITEIO_H
#define C2_WRITEIO_H

#include <DeepMain.h>

void WRITE_IO_wstr(FILE* fp, wString str) {
    size_t len = size(str);
    fwrite(&len, sizeof(size_t), 1, fp);
    fwrite(&str.buff, sizeof(char*), 1, fp);
}

void WRITE_IO_wi(FILE* fp, int n) { fwrite(&n, sizeof(int), 1, fp); }

void WRITE_IO_wtr(FILE* fp, triplet tr) { fwrite(&tr, sizeof(triplet), 1, fp); }

#endif //C2_WRITEIO_H
