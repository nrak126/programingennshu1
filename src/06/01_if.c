#include <stdio.h>

int main(int argc, const char *argv[]) {
    int a;
    printf("a? ");
    scanf("%d", &a);

    if(a > 0) {
        printf("aは正の値です\n");
    } else if(a == 0) {
        printf("aは0です\n");
    } else {
        printf("aは負の値です\n");
    }

    return 0;
}
