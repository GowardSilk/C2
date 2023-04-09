#include <Generator.h>
#include <WriteIO.h>

void reactor_function(wString* str) {
    wString* ans = init(MAX_WSTR_SZ*2);
    int index = 0;
    for(short i = 0; i < MAX_WSTR_SZ*2; i++) {
        for(short j = 0; j < 26; j++) {
            if(str->buff[i] == LOWER_ARR[j]) {
            }
        }
    }
}

int main(void) {

    FILE* fp;
    fopen_s(&fp, "Reactor4.dat", "wb");
    for(short i = 0; i < 10; i++) {
        wString in = init_s(GEN_str(LOWER_ARR, 26));
        WRITE_IO_wstr(fp, in);
        printf("IN: %s\n", in.buff);
        reactor_function(&in);
        WRITE_IO_wstr(fp, in);
        printf("EX: %s\n", in.buff);
        free(in.buff);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}