#include <stdio.h>
/*
void hasDuplicateDigit (int a[])
{

}
*/
void separateDigit (int n, int a[])
{
    int i;
    for(i = 4 ; i > 0 ; i--)//測試過了是對的!
    {        
        a[i-1] = n % 10;
        n = n / 10;
    }
}

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
            if(a[i] == b[j])
                count++;
        }
    }
}

int main ()
{
    int hidden[10], guess[10];
    int i, rand;
    // setHiddenAnswer(hidden);    
    separateDigit(9527, hidden);
    // guessing(guess);
    //printf("請猜一個 4 位數不重覆的數字："); scanf("%d", &guess);
    separateDigit(7523, guess);
    printf("%d A %d B\n", checkA(hidden, guess), checkB(hidden, guess) - checkA(hidden, guess));
    return 0;
}