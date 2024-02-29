#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void example(char **argv) {
    strcpy(argv[0], "test11111111111111111111111111123480239840923840298349999");
}

void example2(char *argv[]) {
    strcpy(argv[0], "test2");
}

void example3(char argv[2][4]) {
    // strcpy(argv[0], "test3"); // don't do that, use strncpy
    printf("%s\n", argv[0]);
}

int main() {
    // char **argv = malloc(sizeof(char *) * 2);
    // for (size_t i = 0; i < 2; i++)
    // {
    //     argv[i] = malloc(sizeof(char) * 4);
    //     strcpy(argv[i], "AAAA");
    // }

    char argv[2][4] = {"aaa", "bbb"};

    
    // execlp("whoami", "whoami", NULL);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);

    example(argv);
    printf("%s\n", argv[0]);

    example2(argv);
    printf("%s\n", argv[0]);

    example3(argv);
    printf("%s\n", argv[0]);
    return 0;
}
