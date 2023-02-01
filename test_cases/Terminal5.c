#include <WriteIO.h>
#include <Generator.h>

void swap(triplet *a, triplet *b) {
    triplet temp = *a;
    *a = *b;
    *b = temp;
}

void terminal_function(TripletContainer *container) {
    int i, j;
    for (i = 0; i < sizeof(container->array)/sizeof(triplet); i++) {
        for (j = 0; j < sizeof(container->array)/sizeof(triplet) - i - 1; j++) {
            if (container->array[j]._triplet_unit_1 > container->array[j+1]._triplet_unit_1) {
                triplet temp = container->array[j];
                container->array[j] = container->array[j + 1];
                container->array[j + 1] = temp;
            }
        }
    }
}


int main() {

    FILE* fp;
    fopen_s(&fp, "Terminal5.dat", "wb");
    if(fp != NULL) {
        for(short i = 0; i < 10; i++) {
            TripletContainer inp = init(6);
            printf("TEST %i\n", i);
            for(short j = 0; j < 5; j++) {
                triplet randtr = GEN_tr();
                trprintf(&randtr);
                //printf("{%i}", randtr._triplet_unit_1 + randtr._triplet_unit_2 + randtr._triplet_unit_3);
                push_back(&inp, &randtr);
                //WRITE_IO_wtr(fp, randtr);
            }
            printf("\n");
            terminal_function(&inp);
            for(short j = 0; j < 5; j++) {
                trprintf(at(&inp, j));
                //printf("{%i}", at(&inp, j)->_triplet_unit_1 + at(&inp, j)->_triplet_unit_2 + at(&inp, j)->_triplet_unit_3);
                WRITE_IO_wtr(fp, *at(&inp, j));
            }
            release(&inp);
            printf("\nTEST END\n");
        }
        fclose(fp);
    }
    else { printf("could not load file!"); }

    return EXIT_SUCCESS;
}