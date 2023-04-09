#ifndef C2_GENERATOR_H
#define C2_GENERATOR_H

#define TR_UNIT_MAX_SZ 100

#include <DeepMain.h>

static const char LOWER_ARR[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'
};

static const char UPPER_ARR[26] = {
    'a'-32, 'b'-32, 'c'-32, 'd'-32, 'e'-32, 'f'-32,
    'g'-32, 'h'-32, 'i'-32, 'j'-32, 'k'-32, 'l'-32,
    'm'-32, 'n'-32, 'o'-32, 'p'-32, 'q'-32, 'r'-32,
    's'-32, 't'-32, 'u'-32, 'v'-32, 'w'-32, 'x'-32,
    'y'-32, 'z'-32
};

static const char MIXED_ARR[52] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', 
    'a'-32, 'b'-32, 'c'-32, 'd'-32, 'e'-32, 'f'-32,
    'g'-32, 'h'-32, 'i'-32, 'j'-32, 'k'-32, 'l'-32,
    'm'-32, 'n'-32, 'o'-32, 'p'-32, 'q'-32, 'r'-32,
    's'-32, 't'-32, 'u'-32, 'v'-32, 'w'-32, 'x'-32,
    'y'-32, 'z'-32
};

char* GEN_str(const char ARR[], int l) {
    char* buff = malloc(MAX_WSTR_SZ);
    for(size_t i = 0; i < MAX_WSTR_SZ-1; i++)
        buff[i] = ARR[rand() % l];
    buff[MAX_WSTR_SZ-1] = '\0';
    return buff;
}

sString GEN_sstr(const char ARR1[], int l1, const char ARR2[], int l2) {
    return (sString) {
        .value = {
            .buff = GEN_str(ARR1, l1)
        },
        .key = {
            .buff = GEN_str(ARR2, l2)
        }
    };
}


int GEN_int(int from, int to) {
    int r = rand() % to;
    return r < from ? GEN_int(from, to) : r;
}

triplet GEN_tr() {
    return (triplet) {
        ._triplet_unit_1 = rand() % TR_UNIT_MAX_SZ,
        ._triplet_unit_2 = rand() % TR_UNIT_MAX_SZ,
        ._triplet_unit_3 = rand() % TR_UNIT_MAX_SZ
    };
}

#endif //C2_GENERATOR_H
