#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "7") == 0) {
        printf("pecan{st4t1c_f0r_th3_w1n!}\n");
    } else {
        printf("Failure\n");
    }

    return 0;
}