#ifndef C2_READIO_H
#define C2_READIO_H

#include <DeepMain.h>

#define READ_IO_rethelper(ret_Ty, what, sz) \
struct READ_IO_rethelper##ret_Ty { \
    bool is_malloc; \
    ret_Ty ret_mem; \
    what to_free[sz]; \
    short to_free_sz; \
}

READ_IO_rethelper(wString, char*, 1); //is malloced
READ_IO_rethelper(triplet, void*, 1); //not malloced
READ_IO_rethelper(int    , void*, 1); //not malloced
READ_IO_rethelper(TripletContainer, struct triplet_*, 1); //is malloced
READ_IO_rethelper(sString, void*, 2); //is malloced (x2)

struct READ_IO_rethelperwString READ_IO_rwString(FILE* fp) {
    size_t len = 0;
    if(fread(&len, sizeof(size_t), 1, fp) != 1)
        printf("[READ_IO_rwString]: could not read len!\n");
    char* buff = malloc(sizeof(char)*len);
    if(fread(buff, len, 1, fp) != 1)
        printf("[READ_IO_rwString]: could not read buff!\n");
    return (struct READ_IO_rethelperwString) {
        .is_malloc = true,
        .ret_mem = (wString) {
            .buff = buff
        },
        .to_free[0] = buff,
        .to_free_sz = 1
    };
}

struct READ_IO_rethelperint READ_IO_rint(FILE* fp) {
    int n = 0;
    fread(&n, sizeof(int), 1, fp);
    return (struct READ_IO_rethelperint) {
        .is_malloc = false,
        .ret_mem = n,
        .to_free = NULL,
        .to_free_sz = 0
    };
}

struct READ_IO_rethelpertriplet READ_IO_rtriplet(FILE* fp) {
    triplet tr = init(0, 0, 0);
    if(fread(&tr, sizeof(triplet), 1, fp) != 1)
        printf("[READ_IO_rtriplet]: failed to read triplet!\n");
    return (struct READ_IO_rethelpertriplet) {
        .is_malloc = false,
        .ret_mem = tr,
        .to_free = NULL,
        .to_free_sz = 0
    };
}

/* BE CAREFUL ! The function does not take length of TripletContainer, so it reads only predefined value! */
struct READ_IO_rethelperTripletContainer READ_IO_rTripletContainer(FILE* fp) {
    TripletContainer tr_con = init_s(6); //malloc...
    for(short i = 0; i < 5; i++) {
        triplet tr = READ_IO_rtriplet(fp).ret_mem;
        push_back(&tr_con, &tr);
    }
    return (struct READ_IO_rethelperTripletContainer) {
        .is_malloc = true,
        .ret_mem = tr_con,
        .to_free[0] = tr_con.array,
        .to_free_sz = 1
    };
}

struct READ_IO_rethelpersString READ_IO_rsString(FILE* fp) {
    struct READ_IO_rethelperwString key = READ_IO_rwString(fp);
    struct READ_IO_rethelperwString val = READ_IO_rwString(fp);
    return (struct READ_IO_rethelpersString) {
        .is_malloc = true,
        .ret_mem = (sString) {
            .key   = key.ret_mem,
            .value = val.ret_mem
        },
        .to_free[0] = key.to_free[0],
        .to_free[1] = val.to_free[0],
        .to_free_sz = 2
    };
}

#endif //C2_READIO_H
