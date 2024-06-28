#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    double theta, rad;

    printf("input: ");
    scanf("%lf", &theta);

    rad = theta / 180 * M_PI;
    printf("sin (%f) = %f\n", theta, sin(rad));

    return 0;
}