#ifndef C2_WRITEIO_H
#define C2_WRITEIO_H

#include <DeepMain.h>

void WRITE_IO_wstr(FILE* fp, wString str) {
    size_t len = strlen(str.buff);
    fwrite(&len, sizeof(size_t), 1, fp);
    fwrite(str.buff, len, 1, fp);
}

void WRITE_IO_sstr(FILE* fp, sString str) {
    WRITE_IO_wstr(fp, str.key);
    WRITE_IO_wstr(fp, str.value);
}

void WRITE_IO_wi(FILE* fp, int n) { fwrite(&n, sizeof(int), 1, fp); }

size_t WRITE_IO_wtr(FILE* fp, triplet tr) { return fwrite(&tr, sizeof(triplet), 1, fp); }

#endif //C2_WRITEIO_H
