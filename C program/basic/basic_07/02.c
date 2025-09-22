#include <stdio.h>
int an(int j, int m, int n, int s, int t);
int main()
{
    int i, j, sets, m, n, s, t, index;
    printf("How many sets of test data: "); scanf("%d", &sets);
    for(i=0 ; i<sets ; i++)
    {
        printf("\nm = "); scanf("%d", &m);
        printf("n = "); scanf("%d", &n);
        printf("s = "); scanf("%d", &s);
        printf("t = "); scanf("%d", &t);
        printf("Final index = "); scanf("%d", &index);
        for(j=0 ; j<=index ; j++)
        {
            printf("a_%d = %d\n", j, an(j, m, n, s, t));
        }
    }
}
int an(int j, int m, int n, int s, int t)
{
    if(j==0) return 0;
    else
        if (j%2 != 0) return m * an(j-1, m, n, s, t) + n;
        else return s * an(j-1, m, n, s, t) + t;
}