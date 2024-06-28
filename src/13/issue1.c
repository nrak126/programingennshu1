#include <math.h>
#include <stdio.h>

double calcArea(double r) { return M_PI * pow(r, 2); }
double calcCircumference(double r) { return 2 * M_PI * r; }

int main(int argc, char *argv[]) {
    double r;

    printf("input r: ");
    scanf("%lf", &r);

    printf("%f %f\n", calcArea(r), calcCircumference(r));

    return 0;
}