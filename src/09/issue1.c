#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[3] = {0};
    int b[3] = {0};
    for(int i = 0; i < 3; i++) {
        printf("a[%d]? ", i);
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("b[%d]? ", i);
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("a[%d] - b[%d] = %d\n", i, i, a[i] - b[i]);
    }
    return 0;
}