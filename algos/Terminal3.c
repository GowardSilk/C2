#include <Terminal_prcl.h>

triplet terminal_function(TripletContainer tr_con) {
    triplet* tr = at(&tr_con, 0);
    for(size_t i = 0; i < size(&tr_con); i++) {
        if(!CMP_is_higher(tr, at(&tr_con, i))) { tr = at(&tr_con, i); }
    }
    return *tr;
}

HIJACK(Terminal_prcl, triplet, TripletContainer);

int main(void) {
    terminal_type tt = { .pt = B_301 };
    Terminal_prcl terminal = init(tt);
    hijack(&terminal, terminal_function);
    override(&terminal);
}