#include <stdio.h>
int Cnk(int n, int k);
int main()
{
    int n, k;
    for(n=1 ; n<=6 ; n++)
    {
        for(k=0 ; k<=6 ; k++)
        {
            printf("C(%d, %d) = %d\n", n, k, Cnk(n, k));
            if(n==k) break;
        }
    }
}
int Cnk(int n, int k)
{
    if( k==0 ) return 1;
    if( k==n ) return 1;
    else return Cnk(n-1, k-1) + Cnk(n-1, k);
}