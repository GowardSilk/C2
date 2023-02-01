#include <Terminal_prcl.h>

triplet terminal_function(triplet tr) {
    return (triplet) {
            ._triplet_unit_1 = tr._triplet_unit_3,
            ._triplet_unit_2 = tr._triplet_unit_2,
            ._triplet_unit_3 = tr._triplet_unit_1,
    };
}

int main() {
    terminal_type tt = { .tt = B_236 };
    Terminal_prcl terminal = init(tt);
    hijack(&terminal, terminal_function);
    override(&terminal);
}