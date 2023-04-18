#include <Terminal_prcl.h>

triplet terminal_function(triplet tr) {
//    printf("??");
    return (triplet) {
        ._triplet_unit_1 = tr._triplet_unit_3,
        ._triplet_unit_2 = tr._triplet_unit_2,
        ._triplet_unit_3 = tr._triplet_unit_1,
    };
}

HIJACK(Terminal_prcl, triplet, triplet);

int main(void) {
    terminal_type tt = {.pt = A_220};
    Terminal_prcl terminal = init(tt);
    hijack(&terminal, terminal_function);
    override(&terminal);
}