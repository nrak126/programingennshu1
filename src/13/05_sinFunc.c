#include <math.h>
#include <stdio.h>

double deg2Rad(double theta) { return theta / 180 * M_PI; }

int main(int argc, const char *argv[]) {
    double theta, rad;

    printf("input: ");
    scanf("%lf", &theta);

    rad = deg2Rad(theta);
    printf("sin (%f) = %f\n", theta, sin(rad));

    return 0;
}