#include <stdio.h>
#include <math.h>
void meanValue(double *a, double *b, double *aMean, double *gMean, double *hMean);
int main() 
{
    double a, b, aMean, gMean, hMean;
    int ti, repeatTimes;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes);
    for (ti = 0; ti < repeatTimes; ti++) 
    {
        printf("\nPlease input two numbers: ");
        scanf("%lf%lf", &a, &b);
        meanValue(&a, &b, &aMean, &gMean, &hMean);
        printf("The arithmetic mean of %f and %f is %f\n", a, b, aMean);
        printf("The geometric mean of %f and %f is %f\n", a, b, gMean);
        printf("The harmonic mean of %f and %f is %f\n", a, b, hMean);
    }
    return 0;
}
void meanValue(double *a, double *b, double *aMean, double *gMean, double *hMean)
{
    *aMean = (*a+*b)/2;
    *gMean = sqrt((*a**b));
    if (*a+*b == 0) *hMean = 0;
    else *hMean = (2**a**b)/(*a+*b);
}//sqrt(x)