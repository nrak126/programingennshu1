//
//  04_issue1_K24142.c
//  prg1
//
//  Created by k24142kk on 2024/05/09.
//

#include <stdio.h>
int main(int argc, const char *argv[]) {
    int height, weight;
    double standardWeight, bmi;

    printf("height? ");
    scanf("%d", &height);
    printf("weight? ");
    scanf("%d", &weight);

    // 標準体重
    standardWeight = (height - 100) * 0.9;

    // BMI
    bmi = weight / (height / 100.0 * height / 100.0);

    printf("standardWeight = %f\n", standardWeight);
    printf("BMI = %f\n", bmi);
    return 0;
}
