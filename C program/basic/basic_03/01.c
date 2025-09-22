#include <stdio.h>
int main()
{
    int i,student[101]={0},num,score,interval, stat[101]={0},upper=0,lower=0,count,a=0;//stat[101]要給值，不然就會是一堆怪怪的數字，所以應該要長這樣stat[101]={0}
    printf("Number of students: "); scanf("%d", &num);
    printf("Score interval: "); scanf("%d", &interval);
    for(i=0;i<num;i++)
    {
        printf("Student#%d's score: ",i+1); scanf("%d",&score);
        student[i]=score;
        score=score/interval;
        stat[score]++;
    }
    printf("\nScoreRange People BarChart\n");
    while(1)
    {
        a=a+interval;
        if(a>=100)
        break;
    }
    a=a/interval;
    if(a*interval<=100)
    a++;
    for(i=0;i<a;i++)
    {
        printf("%3d ~ %3d %5d    ", lower, upper+interval-1, stat[i] );
        lower=upper+interval;
        upper=upper+interval;
        count=0;//要記得歸零
        while(stat[i]>0)
        {
            printf("*");
            count++;
            if(count==stat[i])
            break;
        }
        printf("\n");
    }
}