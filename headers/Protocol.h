#ifndef C2_PROTOCOL_H
#define C2_PROTOCOL_H

//here will come the definition for file_dest
const char* file_dest = "Terminal2.dat";

// #define MULTIP_F_HOLDER
#ifndef MULTIP_F_HOLDER
#define HIJACK(PRCL, ex_Ty, in_Ty) \
static void hijack(PRCL* this, ex_Ty(*func)(in_Ty)) { \
    if(this->pt.pt == 0) \
        abort(); \
    FILE* fp; \
    fopen_s(&fp, file_dest, "rb"); \
    for(short i = 0; i < 10; i++) { \
        in_Ty in = READ_IO_r##in_Ty(fp); \
        ex_Ty ex = READ_IO_r##ex_Ty(fp); \
        if(CMP_is_equal((*func)(in), ex)) \
            this->hack_success += 0.1f;\
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
        in_Ty1 in1 = READ_IO_r##in_Ty1(fp); \
        in_Ty2 in2 = READ_IO_r##in_Ty2(fp); \
        ex_Ty  ex  = READ_IO_r##ex_Ty(fp); \
        if(CMP_is_equal((*func)(in1, in2), ex)) \
            this->hack_success += 0.1f; \
    } \
    fclose(fp); \
}
#endif //!MULTIP_F_HOLDER

#endif //!C2_PROTOCOL_H