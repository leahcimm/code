#include <stdio.h>
#include <math.h>

int main()
{
    double x,toler,sum=0,new=1,keep,term;
    int k=1;
    printf("請輸入 x : "); scanf("%lf",&x);
    printf("請輸入容許誤差值："); scanf("%lf",&toler);
    term=x;
    while(fabs(term)>=toler)
    {        
        sum=sum+term;
        term=-(term*x*x)/(k+1)/(k+2);
        k=k+2;        
    }    
    printf("sin(%f) ~= %.20f\n",x,sum);
    printf("sin(%f) == %.20f",x,sin(x));
}