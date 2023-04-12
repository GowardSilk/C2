#ifndef C2_READIO_H
#define C2_READIO_H

#include <DeepMain.h>

#define READ_IO_rethelper(ret_Ty, what) \
struct READ_IO_rethelper##ret_Ty { \
    bool is_malloc; \
    ret_Ty ret_mem; \
    what   to_free; \
}

READ_IO_rethelper(wString, char*);
READ_IO_rethelper(triplet, void*);
READ_IO_rethelper(int    , void*);
READ_IO_rethelper(TripletContainer, struct triplet_*);
READ_IO_rethelper(sString, void*);

struct READ_IO_rethelperwString READ_IO_rwString(FILE* fp) {
    size_t len = 0;
    fread(&len, sizeof(size_t), 1, fp);
    char* buff = malloc(sizeof(char)*len);
    printf("malloc\n");
    fread(&buff, sizeof(char), len, fp);
    return (struct READ_IO_rethelperwString) {
        .is_malloc = true,
        .ret_mem = (wString) {
            .buff = buff
        },
        .to_free = buff
    };
}

struct READ_IO_rethelperint READ_IO_rint(FILE* fp) {
    int n = 0;
    fread(&n, sizeof(int), 1, fp);
    return (struct READ_IO_rethelperint) {
        .is_malloc = false,
        .ret_mem = n,
        .to_free = NULL
    };
}

struct READ_IO_rethelpertriplet READ_IO_rtriplet(FILE* fp) {
    triplet tr = init(0, 0, 0);
    fread(&tr, sizeof(triplet), 1, fp);
    return (struct READ_IO_rethelpertriplet) {
        .is_malloc = false,
        .ret_mem = tr,
        .to_free = NULL
    };
}

/* BE CAREFUL ! The function does not take length of TripletContainer, so it reads only predefined value! */
struct READ_IO_rethelperTripletContainer READ_IO_rTripletContainer(FILE* fp) {
    TripletContainer tr_con = init_s(5); //malloc...
    for(short i = 0; i < 5; i++) {
        triplet tr = READ_IO_rtriplet(fp).ret_mem;
        push_back(&tr_con, &tr);
    }
    return (struct READ_IO_rethelperTripletContainer) {
        .is_malloc = true,
        .ret_mem = tr_con,
        .to_free = tr_con.array
    };
}

sString READ_IO_rsString(FILE* fp);

#endif //C2_READIO_H
