#include <stdio.h>
void devB(int a, int b, int c) {
    if(a == 1) {
        printf("GO ");
    } else if(b == 1 && c == 1) {
        printf("GO ");
    } else if(b == 0 && c == 1) {
        printf("GO ");
    } else {
        printf("NO ");
    }
}
int main() {
    for(int i = 0; i < 8; i++) {
        devB(i / 4 % 2, i / 2 % 2, i % 2);
    }
    printf("\n");
    return 0;
}