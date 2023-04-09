#include <Generator.h>
#include <WriteIO.h>
#include <ctype.h>

void reactor_function(wString* str) {
    for(size_t i = 0; str->buff[i] != '\0'; i++) {
        if(islower(str->buff[i])) { str->buff[i] -= 32; }
        else { str->buff[i] += 32; }
    }
}

int main(void) {

    FILE* fp;
    fopen_s(&fp, "Reactor2.dat", "wb");
    for(short i = 0; i < 10; i++) {
        wString in = init_s(GEN_str(MIXED_ARR, 52));
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