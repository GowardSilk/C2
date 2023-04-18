#include <WriteIO.h>
#include <Generator.h>

void swap(triplet *a, triplet *b) {
    triplet temp = *a;
    *a = *b;
    *b = temp;
}

void terminal_function(TripletContainer *container) {
    int i, j;
    for (i = 0; i < container->size; i++) {
        for (j = 0; j < container->size - i - 1; j++) {
            if (CMP_is_higher(container->array[j], container->array[j+1])) {
//                triplet temp = container->array[j];
//                container->array[j] = container->array[j + 1];
//                container->array[j + 1] = temp;
                swap(&container->array[j], &container->array[j+1]);
            }
        }
    }
}


int main() {

    FILE* fp;
    fopen_s(&fp, "Terminal5.dat", "wb");
    if(fp != NULL) {
        for(short i = 0; i < 10; i++) {
            TripletContainer inp = init_s((size_t)6);
            printf("TEST %i\n", i+1);
            for(short j = 0; j < 5; j++) {
                triplet randtr = GEN_tr();
                trprintf(&randtr);
                printf("...{%i}\n", randtr._triplet_unit_1 + randtr._triplet_unit_2 + randtr._triplet_unit_3);
                push_back(&inp, &randtr);
                WRITE_IO_wtr(fp, randtr);
            }
            printf("\n");
            terminal_function(&inp);
            for(short j = 0; j < 5; j++) {
                trprintf(at(&inp, j));
                printf("...{%i}\n", at(&inp, j)->_triplet_unit_1 + at(&inp, j)->_triplet_unit_2 + at(&inp, j)->_triplet_unit_3);
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