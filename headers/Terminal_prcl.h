#ifndef C2_TERMINAL_PRCL_H
#define C2_TERMINAL_PRCL_H

#include <DeepMain.h>
#include <ReadIO.h>

enum _TERMINAL {
    T_DISCONNECTED,
    A_220,
    B_236, B_301, B_524,
    C_303, C_246, C_954, C_282,
    D_702, D_443, D_230, D_990, D_102
};

typedef struct terminal_type_ {
    enum _TERMINAL tt;
} terminal_type;

typedef struct wrd_Terminal_prcl_ {
    terminal_type tt;
    float hack_success;
} wrd_Terminal_prcl;

typedef wrd_Terminal_prcl Terminal_prcl;

static struct wrd_Terminal_prcl_ __OVERLOAD init(terminal_type tt) {
    return (Terminal_prcl) {
        .hack_success = 0.f,
        .tt = tt
    };
}

// static void __OVERLOAD hijack(Terminal_prcl* this, triplet (*func)(triplet)) {
//     switch(this->tt.tt) {
//         case A_220: {
//             FILE* fp;
//             fopen_s(&fp, "Terminal1.dat", "rb");
//             if(fp != NULL) {
//                 for(short i = 0; i < 10; i++) {
//                     triplet inp = READ_IO_rtriplet(fp);
//                     triplet expec = READ_IO_rtriplet(fp);
//                     if(CMP_is_equal(expec, func(inp))) { this->hack_success += 0.1f; }
//                 }
//             }
//             else { printf("could not open file!"); exit(EXIT_FAILURE); }
//         } break;
//     }
// }

#define F_HOLDER__TR_TR

#ifdef  F_HOLDER__TR_TR
    const char* file_dest = "Terminal1.dat";
    #define hijack(TR_PRCL, FUNC, in_Ty, ex_Ty) \
    static void __NORETURN __OVERLOAD hijack(Terminal_prcl* this, ex_Ty(*func)(##in_Ty)) { \
        if(this->tt == T_DISCONNECTED) { \
            throw\
        } \
        FILE* fp; \
        fopen_s(&fp, file_dest, "rb"); \
        for(short i = 0; i < 10; i++) { \
            ##in_Ty in = READ_IO_r##in_Ty(fp); \
            ##ex_Ty ex = READ_IO_r##ex_Ty(fp); \
            if(CMP_is_equal((*func)(in), ex)) { \
                this->hack_success += 0.1f;\
            } \
        } \
        fclose(fp); \
    }
#endif

static void override(Terminal_prcl* this) {
    printf("%f", this->hack_success);
}

#endif //C2_TERMINAL_PRCL_H
