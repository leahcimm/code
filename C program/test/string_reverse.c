#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=5,i;
    char str1[]={'a','b','b','b','b'};//char str1[]="abcde";//char str[]={'a','b',......}
    for(i=0 ; i<n/2 ; i++)
    {
        int j = str1[i];
        str1[i] = str1[n-i-1];
        str1[n-1-i] = j;
    }

    for( i=0 ; i < n ; i++ )
        printf("%c",str1[i]);
}