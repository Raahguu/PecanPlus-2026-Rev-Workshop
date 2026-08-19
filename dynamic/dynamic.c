#include <stdio.h>
#include <string.h>

char* get_flag() {
    static char enc[] = "%064;.1,;a8d6(";

    int key = 0x55;

    for (int i = 0; i < 14; i++)
    {
        enc[i] ^= key;
    }

    return enc;
}

int main() {
    printf("Getting flag\n");
    char* flag = get_flag();
    printf("Got flag\n");
    return 0;
}