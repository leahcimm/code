#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int occur[13]={0},i,sum=0,count=0;
    srand((unsigned int)time(NULL));//初始化亂數
    for(i=0;i<6000;i++)
    {
        int k = rand() % 6 + 1;
        int m = rand() % 6 + 1; // get a random number between 0 ~ (N-1)
        sum=m+k;        
        occur[sum%13]++;//run 不出來的原因是因為%後面的數字錯了      
    }
    for(i=2;i<13;i++)
    {
        printf("%d 出現過 %d 次\n",i,occur[i]);
    }
        
    return 0;
}