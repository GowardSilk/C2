#include <Generator.h>
#include <WriteIO.h>

wString* reactor_function(sString sStr) {
    wString* ans = (wString*)init(MAX_WSTR_SZ);
    short end = 0;
    for(short i = 0; i < strlen(sStr.value.buff); i++) {
        for(short j = 0; j < strlen(sStr.key.buff); j++) {
            if(sStr.value.buff[i] == sStr.key.buff[j]) {
                ans->buff[end] = sStr.value.buff[i];
                end++;
            }
        }
    }
    return ans;
}

int main(void) {

    FILE* fp;
    fopen_s(&fp, "Reactor3.dat", "wb");
    for(short i = 0; i < 10; i++) {
        wString value = init_s(GEN_str(LOWER_ARR, 26));
        WRITE_IO_wstr(fp, value);
        int sz = GEN_int(1, MAX_WSTR_SZ);
        wString* key = init(sz);
        for(int j = 0; j < sz; j++)
            key->buff[j] = value.buff[GEN_int(0, MAX_WSTR_SZ-1)];
        printf("IN: {%s, %s}\n", value.buff, key->buff);
        wString* ex = reactor_function((sString){
            .value = value,
            .key = *key
        });
        WRITE_IO_wstr(fp, *ex);
        printf("EX: %s\n", ex->buff);
        free(ex);
        free(key->buff);
        free(value.buff);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}