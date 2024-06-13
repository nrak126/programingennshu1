#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    printf("n? ");
    scanf("%d", &n);

    switch(n) {
    case 1:
        printf("AAA\n");
        break;

    case 2:
        printf("BBB\n");
        break;

    default:
        printf("Defaultです.\n");
        break;
    }

    return 0;
}