#include <stdio.h>
int GCD(int a, int b);
int main()
{
    int i, sets, a, b, gcd;
    printf("How many sets of test data: "); scanf("%d",&sets);
    for(i=0 ; i<sets ; i++)
    {
        printf("\na = "); scanf("%d", &a);
        printf("b = "); scanf("%d", &b);
        printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b)); 
    }
}
int GCD(int a, int b)
{
    if( b==0 ) return a;
    GCD(b, a % b);
}