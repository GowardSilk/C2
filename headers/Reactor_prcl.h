#ifndef C2_REACTOR_PRCL_H
#define C2_REACTOR_PRCL_H

#include <Protocol.h>

#include <DeepMain.h>
#include <Protocol.h>

enum _REACTOR_ {
    R_DISCONNECTED = 0,
    IMPACT_v1_2A = 1,
    IMPACT_v0_9 = 2,
    TWINX_B = 3,
    COLOSSUS_v0_5 = 4,
    MARSCHAL_v014 = 5,
    BUCKLAND_EX = 6,
    JAMBO_v1_9 = 7,
    PLASIA_v0_2A = 8,
    BEAMX_v093 = 9,
    CITADEL_v2_2B = 10,
    PYRO_ULT = 11,
    ERUPT_v0_2 = 12,
    HADES_v0_45 = 13
};

typedef struct _reactor_type {
    enum _REACTOR_ pt;
} reactor_type;

typedef struct _wrd_Reactor_prcl {
    reactor_type pt;
    float hack_success;
} wrd_Reactor_prcl;

typedef wrd_Reactor_prcl Reactor_prcl;

static struct _wrd_Reactor_prcl __OVERLOAD init(reactor_type pt) {
    return (wrd_Reactor_prcl) {
        .hack_success = 0.f,
        .pt = pt
    };
}

static void override(wrd_Reactor_prcl* rp) {
    printf("%f", rp->hack_success);
}

#endif //C2_REACTOR_PRCL_H
