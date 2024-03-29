#include <WriteIO.h>
#include <Generator.h>

void reactor_function(wString* str) {
    for(size_t i = 0; i < strlen(str->buff); i++)
        str->buff[i] -= 32;
}

int main() {

    FILE* fp;
    fopen_s(&fp, "Reactor1.dat", "wb");
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