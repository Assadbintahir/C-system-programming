#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int result = puts("Hello, world!");

    printf("%d\n", EOF);
    printf("%d\n", result);

    if (result == EOF) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}