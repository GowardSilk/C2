#include <Terminal_prcl.h>

int terminal_function(TripletContainer tr_con) {
    triplet* tr = at(&tr_con, 0);
    for(size_t i = 0; i < size(&tr_con); i++) {
        if(!CMP_is_higher(tr, at(&tr_con, i))) { tr = at(&tr_con, i); }
    }
    return 0;
}

HIJACK(wrd_Terminal_prcl, int, TripletContainer);

int main(void) {
    wrd_Terminal_prcl terminal = init(
            (terminal_type) {
                .pt = B_524
            });
    hijack(&terminal, terminal_function);
    override(&terminal);
    return EXIT_SUCCESS;
}