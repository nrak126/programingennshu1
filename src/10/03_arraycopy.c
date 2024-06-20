#include <stdio.h>

int main(int argc, const char *argv[]) {
    int heightsCm[5];
    double heightsMeter[5];

    for(int i = 0; i < 5; i++) {
        printf("%d人目の身長(cm)? ", i + 1);
        scanf("%d", &heightsCm[i]);
    }
    printf("--- Convert Meter ---\n");
    for(int i = 0; i < 5; i++) {
        heightsMeter[i] = heightsCm[i] / 10.0;
        printf("%d人目の身長: %lf m\n", i + 1, heightsMeter[i]);
    }
    return 0;
}