#ifndef C2_GENERATOR_H
#define C2_GENERATOR_H

#define TR_UNIT_MAX_SZ 100

#include <DeepMain.h>

const char ARR[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'
};

wString GEN_str() {
    char buff[MAX_WSTR_SZ];
    for(size_t i = 0; i < MAX_WSTR_SZ; i++) {
        buff[i] = ARR[rand() % 26];
    }
    return (wString) {
        .buff = buff
    };
}

triplet GEN_tr() {
    return (triplet) {
        ._triplet_unit_1 = rand() % TR_UNIT_MAX_SZ,
        ._triplet_unit_2 = rand() % TR_UNIT_MAX_SZ,
        ._triplet_unit_3 = rand() % TR_UNIT_MAX_SZ
    };
}

#endif //C2_GENERATOR_H
