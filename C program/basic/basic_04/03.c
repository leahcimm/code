#include <stdio.h>
double myPower(double x, int n)
{
    int i;
    double answer = 1;
    if(n >= 0)
    {
        for(i = 0 ; i < n ; i++)
        {            
            answer *= x;
        }
    }
    else
    {
        n *= -1;
        for(i = 0 ; i < n ; i++)
        {            
            answer /= x;
        }
    }
    
    return answer;
}

int main() 
{
    int ti, repeatTimes, n;
    double x;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes);
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nx = "); scanf("%lf", &x);
        printf("n = "); scanf("%d", &n);
        printf("power(%f, %d) = %f\n", x, n, myPower(x, n));
    }
    return 0;
}
/*
4
3.546
2
3.546
0
-4.1
3
-4.1
4
*/