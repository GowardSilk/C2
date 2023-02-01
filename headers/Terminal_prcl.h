#ifndef C2_TERMINAL_PRCL_H
#define C2_TERMINAL_PRCL_H

#include <DeepMain.h>
#include <ReadIO.h>

enum _TERMINAL {
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

static void __OVERLOAD hijack(Terminal_prcl* this, triplet (*func)(triplet)) {
    switch(this->tt.tt) {
        case A_220: {
            FILE* fp;
            fopen_s(&fp, "Terminal1.dat", "rb");
            if(fp != NULL) {
                for(short i = 0; i < 10; i++) {
                    triplet inp = READ_IO_rtr(fp);
                    triplet expec = READ_IO_rtr(fp);
                    if(CMP_is_equal(expec, func(inp))) { this->hack_success += 0.1f; }
                }
            }
            else { printf("could not open file!"); exit(EXIT_FAILURE); }
        } break;
    }
}

static void __OVERLOAD hijack(triplet (*func)(TripletContainer)) {

}

static void override(Terminal_prcl* this) {
    printf("%f", this->hack_success);
}

#endif //C2_TERMINAL_PRCL_H
