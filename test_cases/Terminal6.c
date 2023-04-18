#include <WriteIO.h>
#include <Generator.h>

triplet terminal_function(TripletContainer* tr_con) {
    for(short i = 0; i < tr_con->size-1; i++) {
        for(short j = i+1; j < tr_con->size; j++) {
            if(tr_con->array[i]._triplet_unit_1 == tr_con->array[j]._triplet_unit_1
            && tr_con->array[i]._triplet_unit_2 == tr_con->array[j]._triplet_unit_2
            && tr_con->array[i]._triplet_unit_3 == tr_con->array[j]._triplet_unit_3) {
                return tr_con->array[i];
            }
        }
    }
    //never gets executed
    return tr_con->array[tr_con->size-1];
}

int main(void) {

    FILE* fp;
    fopen_s(&fp, "Terminal6.dat", "wb");

    if(fp != NULL) {
        for(short i = 0; i < 10; i++) {
            TripletContainer tr_con = init_s(6);
            printf("TEST %i\n", i+1);
            for(short j = 0; j < 5; j++) {
                triplet tr = GEN_tr();
                trprintf(tr);
                WRITE_IO_wtr(fp, tr);
                push_back(&tr_con, &tr);
            }
            //one of those inputs has to be duplicated
            //it can happen that it will not exchange itself
            int x1 = GEN_int(0, 4), x2 = GEN_int(0, 4);
            while(x2 == x1) { x2 = GEN_int(0, 4); }
            printf("\n");
            trprintf(tr_con.array[x1]);
            printf("... %i\n", x1);
            trprintf(tr_con.array[x2]);
            printf("... %i\n", x2);
            tr_con.array[x1] = tr_con.array[x2];
            printf("\n");
            triplet ex = terminal_function(&tr_con);
            trprintf(ex);
            WRITE_IO_wtr(fp, ex);
            release(&tr_con);
            printf("\nTEST END\n");
        }
        fclose(fp);
    }
    else { printf("could not load file!"); }

    return EXIT_SUCCESS;
}