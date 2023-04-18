#include <Reactor_prcl.h>

void reactor_function(wString* str) {
    wString* ans = init(MAX_WSTR_SZ*2);
    int index = 0;
    for(short i = 0; i < MAX_WSTR_SZ*2; i++) {
        for(short j = 0; j < 26; j++) {
            if(str->buff[i] == LOWER_ARR[j]) {
            }
        }
    }
}

int main(void) {
    wrd_Reactor_prcl reactor = init((reactor_type) {.pt = TWINX_B });
    hijack(&reactor, reactor_function);
    override(&reactor);
    return EXIT_SUCCESS;
}