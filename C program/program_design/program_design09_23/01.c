#include <stdio.h>

int main()
{
    int n, m, o, p, q, r;
    printf("Product A 購買數量：");
    scanf("%d", &n);
    printf("Product B 購買數量：");
    scanf("%d", &m);
    if(n < m)
    {
        m = m - n;
        p = m / 2;
        r = m % 2;
        q = ( n * 39 ) + (p * 32)+(r*20);
    }
    
    else if(n > m)
    {
        n = n - m;
        p = n / 2;
        r = n % 2;
        q = ( m * 39 ) + (p * 40)+(r*25);       
    }
    
    else 
    {
        q = m * 39;
    }
    //printf("%d,%d,%d",m,p,r);
    printf("總共是 %d 元", q);
}