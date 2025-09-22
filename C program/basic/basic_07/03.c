#include <stdio.h>
int bn(int b);
int an(int a);
int main()
{
    int i, j, sets, upperLim;
    printf("How many sets of test data: "); scanf("%d", &sets);
    for(i=0 ; i<sets ; i++)
    {
        printf("\nWhat is the upper limit? "); scanf("%d", &upperLim);
        for(j=0 ; an(j+1)<=upperLim ; j++)
        {
            printf("n = %d, (a, b) = (%d, %d)\n", j+1, an(j+1), bn(j+1));
        }
    }
}
int an(int a)
{
    if( a == 1 ) return 1;
    else return an(a-1) + 2 * bn(a-1) + 1;
}
int bn(int b)
{
    if( b == 1 ) return 1;
    else return 3 * an(b-1) - bn(b-1) + 1;
}