#include <stdio.h>
double linear(double x1, double x2, double y1, double y2, double predictNum);
double a, b;
int main()
{
    double x1, x2, y1, y2, predictNum;
    printf("Please input two sets of number!(x1 x2 y1 y2)\n");
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
    linear(x1, x2, y1, y2, 0);//caculate a and b so there's no need to return value
    //printf("%lf %lf", a, b);
    while(1)
    {
        printf("Please input x(input -1 to stop):\n");
        scanf("%lf", &predictNum);
        if(predictNum == -1) break;
        printf("F(%.0f) is %.0f\n", predictNum, linear(0, 0, 0, 0, predictNum));

    }
}
double linear(double x1, double x2, double y1, double y2, double predictNum)
{
    if(predictNum == 0)
    {
        a = (y2 - y1)/(x2 - x1);
        b = y1 - x1*((y2 - y1)/(x2 - x1));
        return 0;
    }
    else
    {
        int F;
        double x = a*predictNum + b;
        //x= x+0.5;
        //printf("%f",x);
        return x;
    }
}
/*
20 30 68 86
50
27
48
92
-1
*/