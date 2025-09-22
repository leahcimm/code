#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int checkA(int a[], int b[])
{
    int i, count = 0;
    for(i = 0 ; i < 4 ; i++)
    {
        if(a[i] == b[i])
            count++;
    }
    return count;
}

int checkB(int a[], int b[])
{
    int i, j, count = 0;
    for(i = 0 ; i < 4 ; i++)
    {
        for(j = 0 ; j < 4 ; j++)
        {
            if(a[i] == b[j] && i != j)// && i != j 學起來
                count++;
        }
    }
    return count;
}

int hasDuplicateDigit (int a[])
{
    int i, count = 0, t = 1, f = 0;
    count = checkB(a,a);/*
    for(i = 1 ; i < 4 ; i++)
    {
        for
        if(a[0] == a[i])
            count++;
    }
    */
    if(count > 0) return t;//有重複
    else return f;
}

void separateDigit (int n, int a[])
{
    int i;
    for(i = 3 ; i >= 0 ; i--)//測試過了是對的!
    {
        a[i] = n % 10;
        n = n / 10;
    }
}
int setHiddenAnswer(int a[])
{
    while(1)
    {
        srand((unsigned int)time(NULL));//初始化亂數
        int h = rand() % 10000;
        separateDigit(h, a);
        if (hasDuplicateDigit(a) == 1) //檢查hidden[]是否有重複
            continue;
        else break;//產生亂數是對的
    }
    return a;
}
void guessing(int a[])
{
    int num, i;
    while(1)
    {
        printf("請猜一個 4 位數不重覆的數字："); scanf("%d", &num);
        if(num<0)
        {   
            printf("只能猜正整數。\n");
            continue;
        }
        if(num>9999)
        {
            printf("只能猜4位數\n");
            continue;
        }
        separateDigit(num, a);
        if (hasDuplicateDigit(a) == 1)
        {
            printf("不能有重覆數字。\n");
            continue;
        }
        else
            break;
    }
}

int main ()
{
    int hidden[10] = {0}, guess[10] = {0};
    int i, h, g, guessTime = 0;
    setHiddenAnswer(hidden);
    for(i = 0 ; i < 4 ; i++)
    {
        printf("%d", hidden[i]);
    }
    while(1)
    {
        guessing(guess);
        guessTime++;
        if (checkA(hidden, guess) == 4)
            break;
        else
        {
            printf("%d A %d B\n", checkA(hidden, guess), checkB(hidden, guess));
            continue;
        }
    }
    printf("Congratulations!\n");
    printf("猜對了！你猜了 %d 次。", guessTime);
    return 0;
}
