#ifndef C2_PROTOCOL_H
#define C2_PROTOCOL_H

#include <ReadIO.h>

//here will come the definition for file_dest
const char* file_dest = "Reactor3.dat";

// #define MULTIP_F_HOLDER
#ifndef MULTIP_F_HOLDER
#define HIJACK(PRCL, ex_Ty, in_Ty) \
static void hijack(PRCL* this, ex_Ty(*func)(in_Ty)) { \
    if(this->pt.pt == 0) \
        exit(EXIT_FAILURE); \
    FILE* fp; \
    fopen_s(&fp, file_dest, "rb"); \
    for(short i = 0; i < 10; i++) { \
        struct READ_IO_rethelper##in_Ty in = READ_IO_r##in_Ty(fp); \
        struct READ_IO_rethelper##ex_Ty ex = READ_IO_r##ex_Ty(fp); \
        if(CMP_is_equal((*func)(in.ret_mem), ex.ret_mem))          \
            this->hack_success += 0.1f;               \
        if(in.is_malloc) { for(short j = 0; j < in.to_free_sz; j++) { free(in.to_free[j]); } } \
        if(ex.is_malloc) { for(short j = 0; j < ex.to_free_sz; j++) { free(ex.to_free[j]); } } \
    } \
    fclose(fp); \
}
#else
#define HIJACK(PRCL, ex_Ty, in_Ty1, in_Ty2) \
static void hijack(PRCL* this, ex_Ty(*func)(in_Ty1, in_Ty2)) { \
    if(this->pt.pt == 0) { \
        abort(); \
    } \
    FILE* fp; \
    fopen_s(&fp, file_dest, "rb"); \
    for(short i = 0; i < 10; i++) { \
        struct READ_IO_rethelper##in_Ty1 in1 = READ_IO_r##in_Ty1(fp); \
        struct READ_IO_rethelper##in_Ty2 in2 = READ_IO_r##in_Ty2(fp); \
        struct READ_IO_rethelper##ex_Ty  ex  = READ_IO_r##ex_Ty(fp); \
        if(CMP_is_equal((*func)(in1, in2), ex)) \
            this->hack_success += 0.1f;     \
        if(in1.is_malloc) { for(short j = 0; j < sizeof(in1.to_free); j++) { free(in1.to_free[j]); } } \
        if(in2.is_malloc) { for(short j = 0; j < sizeof(in2.to_free); j++) { free(in2.to_free[j]); } } \
        if(ex.is_malloc)  { for(short j = 0; j < sizeof(ex.to_free);  j++) { free(ex.to_free[j]);  } } \
    } \
    fclose(fp); \
}
#endif //!MULTIP_F_HOLDER

#endif //!C2_PROTOCOL_H