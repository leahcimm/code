#include <stdio.h>

int main ()
{
    int data, first, upper, common, i, sum=0, an=0;
    printf("How many sets of test data:\n"); scanf("%d", &data);
    printf("\n");
    
    for( i=0 ; i<data ; i++ )
    {
        sum = 0; //sum要歸零 不然還會是剛剛第一圈加過的值
        printf("The first number:\n"); scanf("%d", &first);
        
        printf("The upper limit:\n"); scanf("%d", &upper);
        
        printf("Common difference:\n"); scanf("%d", &common);
        //sum = sum + first; //(1)
        an = first;
        
        while(an <= upper)
        {
            sum = an + sum; //這樣的話就是從第二項開始加，就會少加第一項，所以我就要再寫(1)來先將第一項加入sum中
            an = an + common; //但如果我這樣寫  sum = an + sum; 先把sum加入第一項，就不用再上面寫(1)了
            //printf("%d", an);           //   an = an + common;
        }
        printf("The sum of this arithmetic sequence is %d.\n", sum);
        printf("\n");
    }
    

}
// 3 1 20 3 77 87 5 5 100 26