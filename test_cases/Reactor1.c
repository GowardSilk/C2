#include <WriteIO.h>
#include <Generator.h>

wString reactor_function(wString str) {
    for(size_t i = 0; i < size(str); i++) {
    }
    return (wString) { .buff = 0 };
}

int main() {

    FILE* fp;
    fopen_s(&fp, "Reactor1.dat", "wb");
    for(short i = 0; i < 10; i++) {
        wString str = GEN_str();
        WRITE_IO_wstr(fp, str);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}