#include <Terminal_prcl.h>

triplet terminal_function(triplet tr) {
    return (triplet) {
        ._triplet_unit_1 = tr._triplet_unit_3,
        ._triplet_unit_2 = tr._triplet_unit_1,
        ._triplet_unit_3 = tr._triplet_unit_2,
    };
}

HIJACK(Terminal_prcl, triplet, triplet);

int main() {
    terminal_type tt = { .pt = B_236 };
    Terminal_prcl terminal = init(tt);
    hijack(&terminal, terminal_function);
    override(&terminal);
}