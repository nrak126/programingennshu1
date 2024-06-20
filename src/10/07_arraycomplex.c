#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    int heights[5], weights[5], THRESHOLD = 23;
    double standardWeight, bmi;

    for(int i = 0; i < 5; i++) {
        printf("%d人目の身長と体重? ", i + 1);
        scanf("%d %d", &heights[i], &weights[i]);
    }

    printf("--- しきい値を超えた人 ---\n");

    for(int i = 0; i < 5; i++) {
        standardWeight = (heights[i] - 100) * 0.9;
        bmi = weights[i] / pow(heights[i] / 100.0, 2.0);
        if(THRESHOLD < bmi) {
            printf("%d人目のBMI: %lf, 標準体重との差: %lf\n", i + 1, bmi,
                   weights[i] - standardWeight);
        }
    }
    return 0;
}