#include <stdio.h>

int main()
{
    int i, j, sum = 0, a[10001];
    for(i = 1 ; i <= 10000 ; i++){
        for(j = 1 ; j<i ; j++){
            if(i%j==0)
                sum += j;
        }
        a[i] = sum;
        sum = 0;
        //printf("%d %d\n",i,a[i]);
    }

    for(i = 0 ; i < 10000 ; i++){
        if(i == a[a[i]] && i < a[i] && a[i]<10000){
            printf("(%d, %d)\n", i, a[i]);
        }
        /*for(j = i+1 ; j < 10000 ; j++)
            if(a[i] == j)
                printf("(%d, %d)\n", i, j);*/
    }
}