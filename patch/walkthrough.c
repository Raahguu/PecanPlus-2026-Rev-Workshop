#include <stdio.h>
#include <stdlib.h>

int print_flag() {
    static char enc[] = "%064;.%a!6=f1(";

    int key = 0x55;

    for (int i = 0; i < 14; i++)
    {
        enc[i] ^= key;
    }

    printf("%s\n", enc);

    return 0;
}

int main() {
    exit(0);
    print_flag();
}