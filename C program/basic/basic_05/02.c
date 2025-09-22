#include <stdio.h>
#include <math.h>
int Findgcd(int a, int b);
int Whichbigger(int a, int b);
int main()
{
    int n, i, k, x, s, t;
    double PI=3.14159265358979323846;
    printf("n = ");
    scanf("%d",&k);
    for(int j = 0 ; j <= (k+k) ; j++)
    {
        i = j;
        n = k;
        //if(i>n) n = i; i = k;
        if(i == 0) printf("x = 0 PI, sin(x) = 0.000000, cos(x) = 1.000000\n");
        else if(Findgcd(n, i) == 1)//這裡才是他媽整個程式的重點
            printf("x = %d/%d PI, sin(x) = %f, cos(x) = %f\n", i, n, sin(1.0*i/n*PI), cos(1.0*j/k*PI));
        else //n%i == 0
        {
            if(i==n || i ==2*n)
            printf("x = %d PI, sin(x) = %f, cos(x) = %f\n", i/n, sin(1.0*i/n*PI), cos(1.0*i/n*PI));
            else
            {    
                s = i / Findgcd(n, i);
                t = n / Findgcd(n, i);
                printf("x = %d/%d PI, sin(x) = %f, cos(x) = %f\n", s, t, sin(1.0*s/t*PI), cos(1.0*s/t*PI));
            }
        }
    }
}
int Findgcd(int a, int b)
{
    while(1)
    {
        int c1;
        c1 = a % b;
        if(c1 == 0) break;
        a = b;
        b = c1;
    }
    return b;
}
