#include <Reactor_prcl.h>

wString reactor_function(wString str) {
    for(size_t i = 0; str.buff[i] != '\0'; i++) {
        if(str.buff[i] > 96) { str.buff[i] -= 32; }
        else { str.buff[i] += 32; }
    }
    return str;
}

HIJACK(Reactor_prcl, wString, wString);

int main(void) {
    wrd_Reactor_prcl reactor = init((reactor_type) {.pt = IMPACT_v0_9});
    hijack(&reactor, reactor_function);
    override(&reactor);
    return EXIT_SUCCESS;
}