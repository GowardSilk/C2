#include <Reactor_prcl.h>

wString reactor_function(wString str) {
    for(size_t i = 0; i < strlen(str.buff); i++)
        str.buff[i] -= 32;    
    return str;
}

HIJACK(wrd_Reactor_prcl, wString, wString);

int main(void) {
    wrd_Reactor_prcl reactor = init((reactor_type) {
        .pt = IMPACT_v1_2A
    });
    hijack(&reactor, reactor_function);
    override(&reactor);
    return EXIT_SUCCESS;
}