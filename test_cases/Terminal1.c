#include <WriteIO.h>
#include <Generator.h>

triplet terminal_function(triplet* tr) {
    return (triplet) {
        ._triplet_unit_1 = tr->_triplet_unit_3,
        ._triplet_unit_2 = tr->_triplet_unit_2,
        ._triplet_unit_3 = tr->_triplet_unit_1,
    };
}

int main() {

    FILE* fp;
    fopen_s(&fp, "Terminal1.dat", "wb");
    if(fp != NULL) {
        for(short i = 0; i < 10; i++) {
            triplet inp = GEN_tr();
            triplet expec = terminal_function(&inp);
            WRITE_IO_wtr(fp, inp);
            WRITE_IO_wtr(fp, expec);
        }
        fclose(fp);
    }
    else { printf("could not load file!"); }

    return EXIT_SUCCESS;
}