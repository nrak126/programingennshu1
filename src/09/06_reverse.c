#include <stdio.h>

int main(int argc, const char *argv[]) {
    int input[5] = {0};
    for(int i = 0; i < 5; i++) {
        printf("input[%d]? ", i);
        scanf("%d", &input[i]);
    }
    printf("---reverse---\n");
    for(int i = 4; i >= 0; i--) {
        printf("input[%d]: %d\n", i, input[i]);
    }

    return 0;
}