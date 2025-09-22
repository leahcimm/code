#include <stdio.h>
int isPrime(int n);
int main ()
{
    int sets, input;
    printf("How many sets of test data: ");scanf("%d",&sets);
    for(int i = 0 ; i < sets ; i++)
    {
        printf("\nInput a number (>= 6): ");scanf("%d", &input);
        int k;
        for (int i = 2 ; i < input ; i++)
        {
            for (int j = i ; j < input ; j++) 
            {
                k = input - i - j; // i + j + k = num
                if (isPrime(i) && isPrime(j) && isPrime(k) && i<=j && j<=k)//all i, j, k are prime numbers AND i <= j <= k
                    printf("%d = %d + %d + %d\n", input, i, j, k);//print out input = i + j + k
            }
        }
    }
}
int isPrime(int n)
{
    int i;
    for(i = 2 ; i<=n ; i++)
    {
        if(n % i ==0) //有數可以整除就break所以不是prime
            break;
    }
    if(i == n) return 1;
    else return 0;
}