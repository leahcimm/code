#include <stdio.h>

int main()
{
    //int arr[] = {8,6,4,2,4,2,62,41,9,7,453,5,23,313,34,6456,5}, i, j;
    //int n = sizeof(arr)/sizeof(int);
    insertion();
}

void insertion()
{
    
    int arr[] = {8,6,4,2,4,2,62,41,9,7,453,5,23,313,34,6456,5};
    int n=sizeof(arr)/sizeof(int);
    for( int i=0 ; i < n ; i++ ) printf("%d ",arr[i]);
    printf("\n");
    for(int j=1 ; j<n ; j++)
    {
        int val=arr[j];
        for( int i=j-1 ; i >= 0 ; i-- ) //insert
        {       
            arr[i+1] = arr[i]; 
            if( arr[i] < val )
            {
                arr[i+1] = val;
                break;
            }
            if( i == 0 )
            {
                arr[0]=val;
            }
        }
    }
    

    for(int i=0 ; i<n ; i++) printf("%d ", arr[i]);
}