#include <Terminal_prcl.h>

triplet triplet_function(triplet tr)
{
    return (triplet){
        ._triplet_unit_1 = tr._triplet_unit_3,
        ._triplet_unit_2 = tr._triplet_unit_2,
        ._triplet_unit_3 = tr._triplet_unit_1,
    };
}

int main(void)
{
    terminal_type tt = {.tt = A_220};
    Terminal_prcl terminal = init(tt);
    hijack(&terminal, &triplet_function, triplet, triplet);
    override(&terminal);
}