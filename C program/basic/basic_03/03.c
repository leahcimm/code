#include <stdio.h>
int main()
{
    int data,a[10]={0},i,x,y,j;
    printf("How many sets of test data: "); scanf("%d",&data);
    printf("\n");
    printf("\n");
    for(j=0;j<data;j++)
    {
        printf("x1 = ");scanf("%d",&a[1]);
        printf("y1 = ");scanf("%d",&a[2]);
        printf("a = ");scanf("%d",&a[3]);
        printf("b = ");scanf("%d",&a[4]);
        printf("c = ");scanf("%d",&a[5]);
        printf("r = ");scanf("%d",&a[6]);
        printf("s = ");scanf("%d",&a[7]);
        printf("t = ");scanf("%d",&a[8]);
        printf("n = ");scanf("%d",&a[9]);
        x=a[1];
        y=a[2];
        for(i=0;i<a[9];i++)
        {
            printf("n = %d, (x, y) = (%d, %d)\n",i+1,x,y);
            x=a[3]*a[1]+a[4]*a[2]+a[5];
            y=a[6]*a[1]+a[7]*a[2]+a[8];
            a[1]=x;
            a[2]=y;
        }
        printf("\n");
        printf("\n");
    }
}