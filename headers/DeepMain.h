#ifndef C2_DEEPMAIN_H
#define C2_DEEPMAIN_H

#define MAX_WSTR_SZ 10
#define MAX_TRCON_SZ 15
#define __NORETURN __attribute__((noreturn))
#define __OVERLOAD __attribute__((overloadable))

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//wString region
typedef struct wString_ {
    char* buff;
} wString;

static char __OVERLOAD at(wString str, unsigned pos) {
    if(pos >= strlen(str.buff)) {
        printf("[wString::ERR]: Index out of range!");
        exit(EXIT_FAILURE);
    }
    return str.buff[pos];
}

static size_t __OVERLOAD size_s(wString* str) {
    return strlen(str->buff);
}

static size_t size_s(wString str) {
    return sizeof(str)/sizeof(char);
}

struct wString_ init_s(char* string) {
    return (wString) {
        .buff = string
    };
}

struct wString_* __OVERLOAD init(int sz) {
    return malloc(sz);
}
//!wString region

//sString region
typedef struct _sString {
    wString key;
    wString value;
} sString;
//!sString region

//Triplet region
typedef struct triplet_ {
    int _triplet_unit_1;
    int _triplet_unit_2;
    int _triplet_unit_3;
} triplet;

struct triplet_ __OVERLOAD init(int u1, int u2, int u3) {
    return (triplet) {
        ._triplet_unit_1 = u1,
        ._triplet_unit_2 = u2,
        ._triplet_unit_3 = u3
    };
}

void __OVERLOAD trprintf(triplet tr) {
    printf("{%d, %d, %d}", tr._triplet_unit_1, tr._triplet_unit_2, tr._triplet_unit_3);
}

void __OVERLOAD trprintf(triplet* tr) {
    printf("{%d, %d, %d}", tr->_triplet_unit_1, tr->_triplet_unit_2, tr->_triplet_unit_3);
}
//CMP "operators"
//  see the definition after TripletContainer region
bool __OVERLOAD CMP_is_higher(triplet lhs, triplet rhs);

bool __OVERLOAD CMP_is_higher(triplet* lhs, triplet* rhs);

bool __OVERLOAD CMP_is_equal(triplet lhs, triplet rhs);

bool __OVERLOAD CMP_is_equal(triplet* lhs, triplet* rhs);
//!triplet region

//TripletContainer region
typedef struct TripletContainer_ {
    struct triplet_* array;
    size_t size;
    size_t capacity;
} TripletContainer;

struct TripletContainer_ __OVERLOAD init(size_t icap) {
    return (TripletContainer) {
        .size = 0,
        .capacity = icap,
        .array = (struct triplet_*)malloc(sizeof(struct triplet_) * icap)
    };
}

void push_back(struct TripletContainer_* tr_con, struct triplet_* value) {
    tr_con->size++;
    if (tr_con->size >= tr_con->capacity) {
        tr_con->capacity *= 2;
        tr_con->array = realloc(tr_con->array, sizeof(struct triplet_) * tr_con->capacity);
        printf("Realloc!\n");
    }
    tr_con->array[tr_con->size] = *value;
}

struct triplet_* __OVERLOAD at(struct TripletContainer_* tr_con, size_t index) {
    if(tr_con->size <= index) {
        printf("[TripletContainer::ERR]: Index out of range!");
        exit(EXIT_FAILURE);
    }
    return &tr_con->array[index];
}

void release(struct TripletContainer_* tr_con) {
    free(tr_con->array);
    tr_con->array = NULL;
    tr_con->size = 0;
    tr_con->capacity = 0;
}

void trcprinft(struct TripletContainer_* tr_con) {
    for(size_t i = 0; i < tr_con->size; i++) {
        trprintf(at(tr_con, i));
    }
}

void setcap(struct TripletContainer_* tr_con, size_t cap) {
    tr_con->capacity = cap;
}

size_t size(struct TripletContainer_* tr_con) {
    return tr_con->size;
}
//!TripletContainer region

//CMP "operators"
bool __OVERLOAD CMP_is_higher(triplet lhs, triplet rhs) {
    return (lhs._triplet_unit_1 + lhs._triplet_unit_2 + lhs._triplet_unit_3)
            >
           (rhs._triplet_unit_1 + rhs._triplet_unit_2 + rhs._triplet_unit_3);
}

bool __OVERLOAD CMP_is_higher(triplet* lhs, triplet* rhs) {
    return (lhs->_triplet_unit_1 + lhs->_triplet_unit_2 + lhs->_triplet_unit_3)
           >
           (rhs->_triplet_unit_1 + rhs->_triplet_unit_2 + rhs->_triplet_unit_3);
}

bool __OVERLOAD CMP_is_equal(triplet lhs, triplet rhs) {
    return  lhs._triplet_unit_1 == rhs._triplet_unit_1 &&
            lhs._triplet_unit_2 == rhs._triplet_unit_2 &&
            lhs._triplet_unit_3 == rhs._triplet_unit_3;
}

bool __OVERLOAD CMP_is_equal(triplet* lhs, triplet* rhs) {
    return  lhs->_triplet_unit_1 == rhs->_triplet_unit_1 &&
            lhs->_triplet_unit_2 == rhs->_triplet_unit_2 &&
            lhs->_triplet_unit_3 == rhs->_triplet_unit_3;
}

bool __OVERLOAD CMP_is_equal(int lhs, int rhs) {
    return lhs == rhs;
}

bool __OVERLOAD CMP_is_higher(int lhs, int rhs) {
    return lhs > rhs;
}

bool __OVERLOAD 
//!CMP "operators"

#endif //C2_DEEPMAIN_H
