#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    printf("n? ");
    scanf("%d", &n);

    if(n == 1) {
        printf("AAA\n");
    } else if(n == 2) {
        printf("BBB\n");
    } else {
        printf("Defaultです.\n");
    }

    return 0;
}
