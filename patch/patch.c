#include <stdio.h>
#include <time.h>
#include <string.h>

char* get_flag() {
    static char enc[] = "%064;.,g>\n? `!\n=a%%f;f1(";

    int key = 0x55;

    for (int i = 0; i < 24; i++)
    {
        enc[i] ^= key;
    }

    return enc;
}

int main() {
    time_t seconds;

    time(&seconds);

    if (seconds == 946684800) {
        printf("%s\n", get_flag());
    }

    printf("%ld\n", seconds);

    return 0;
}