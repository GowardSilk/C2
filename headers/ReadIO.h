#ifndef C2_READIO_H
#define C2_READIO_H

#include <DeepMain.h>

wString READ_IO_rwString(FILE* fp) {
    size_t len = 0;
    fread(&len, sizeof(size_t), 1, fp);
    char* buff = malloc(sizeof(char)*len);
    fread(&buff, sizeof(char), len, fp);
    return (wString) {
        .buff = buff
    };
}

int READ_IO_rint(FILE* fp) {
    int n = 0;
    fread(&n, sizeof(int), 1, fp);
    return n;
}

triplet READ_IO_rtriplet(FILE* fp) {
    triplet tr = init(0, 0, 0);
    fread(&tr, sizeof(triplet), 1, fp);
    return tr;
}

/* BE CAREFUL ! The function does not take length of TripletContainer, so it reads only predefined value! */
TripletContainer READ_IO_rTripletContainer(FILE* fp) {
    TripletContainer tr_con = init_s(5);
    for(short i = 0; i < 5; i++) {
        triplet tr = READ_IO_rtriplet(fp);
        push_back(&tr_con, &tr);
    }
    return tr_con;
}

sString READ_IO_rsString(FILE* fp);

#endif //C2_READIO_H
