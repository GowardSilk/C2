#ifndef C2_TERMINAL_PRCL_H
#define C2_TERMINAL_PRCL_H

#include <DeepMain.h>
#include <ReadIO.h>
#include <Protocol.h>

enum _TERMINAL {
    T_DISCONNECTED = 0,
    A_220 = 1,
    B_236 = 2,
    B_301 = 3,
    B_524 = 4,
    C_303 = 5, C_246 = 6, C_954 = 7, C_282 = 8,
    D_702 = 9, D_443 = 10, D_230 = 11, D_990 = 12, D_102 = 13
};

typedef struct terminal_type_ {
    enum _TERMINAL pt;
} terminal_type;

typedef struct wrd_Terminal_prcl_ {
    terminal_type pt;
    float hack_success;
} wrd_Terminal_prcl;

typedef wrd_Terminal_prcl Terminal_prcl;

static struct wrd_Terminal_prcl_ __OVERLOAD init(terminal_type pt) {
    return (Terminal_prcl) {
        .hack_success = 0.f,
        .pt = pt
    };
}

static void override(Terminal_prcl* tp) {
    printf("%f", tp->hack_success);
}

#endif //C2_TERMINAL_PRCL_H
