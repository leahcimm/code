#include <stdio.h>

int main()
{
    int n,i;
    printf("Please input a positive number:\n");
    scanf("%d",&n);
    
    for( i=0 ; i<n ; i++ ) 
    {
        printf("%d / %d = %lf\n", i+1 , i+2 , 1.0*(i+1)/(i+2) );
    }
}