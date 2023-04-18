#include <Reactor_prcl.h>

wString reactor_function(sString sStr) {
    wString ans = init(MAX_WSTR_SZ);
    short end = 0;
    for(short i = 0; i < MAX_WSTR_SZ; i++) {
        for(short j = 0; j < strlen(sStr.key.buff); j++) {
            if(sStr.value.buff[i] == sStr.key.buff[j]) {
                ans.buff[end] = sStr.value.buff[i];
                end++;
            }
        }
    }
    ans.buff[end] = '\0';
    return ans;
}

HIJACK(Reactor_prcl, wString, sString);

int main(void) {
    wrd_Reactor_prcl reactor = init((reactor_type) {.pt = TWINX_B });
    hijack(&reactor, reactor_function);
    override(&reactor);
    return EXIT_SUCCESS;
}