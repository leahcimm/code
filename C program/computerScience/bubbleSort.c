#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int arr[]={8,6,4,2,4,2,62,41,9,7,453,5,23,313,34,6456,5}, i, j;
    int n=sizeof(arr)/sizeof(int);
    for(i=0 ; i<n-1 ; i++)
    {
        for(j=0 ; j+i<n-1 ; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr+j, arr+j+1);
        }
    }

    for( i=0 ;  i < n ; i++ ) printf("%d ",arr[i]);
} 

void swap(int *a, int *b)
{
    int n = *a;
    *a = *b;
    *b = n;
}