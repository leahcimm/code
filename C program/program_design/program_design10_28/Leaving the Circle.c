#include <stdio.h>
int main()
{
    int a[100] = {0};
    int n, k, i, count, nextOrder = 1;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    for(i = 0, count = 0 ; nextOrder <= n ; i++)
    {
        if(i == n) i=0;
        if(a[i]==0) count++;
        if(count/k > 0 && count % k ==0)
            if(a[i] > 0) continue;
            else 
            {
                a[i] = nextOrder;
                nextOrder++;
            }
    }
    for(i = 0 ; i < n ; i++)
    {
        printf("The leaving order of person#%2d is %2d\n", i+1, a[i]);
    }
}