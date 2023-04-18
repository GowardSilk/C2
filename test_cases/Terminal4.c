#include <WriteIO.h>
#include <Generator.h>

int terminal_function(TripletContainer* tr_con) {
    triplet* tr = at(tr_con, 0);
    for(size_t i = 0; i < size(tr_con); i++) {
        if(!CMP_is_higher(tr, at(tr_con, i))) { tr = at(tr_con, i); }
    }
    return 0;
}

int main() {

    FILE* fp;
    fopen_s(&fp, "Terminal4.dat", "wb");
    if(fp != NULL) {
        for(short i = 0; i < 10; i++) {
            TripletContainer inp = init_s(6);
            for(short j = 0; j < 5; j++) {
                triplet randtr = GEN_tr();
                trprintf(randtr);
                push_back(&inp, &randtr);
                WRITE_IO_wtr(fp, randtr);
            }
            int expec = terminal_function(&inp);
            WRITE_IO_wi(fp, expec);
            release(&inp);
        }
        fclose(fp);
    }
    else { printf("could not load file!"); }

    return EXIT_SUCCESS;
}