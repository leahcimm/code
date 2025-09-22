#include <stdio.h>
int check(int input, int a[]);

int main()
{
    int input, a[] = {1234, 2341, 3412, 4123};
    while(1)
    {
        printf("input a serial number:");
        scanf("%d", &input);
        if(check(input, a))
            break;
    }
    printf("qualified!!");
    
}
int check(int input, int a[])
{
    int i;
    for(i=0 ; i<4 ; i++)
    {
        if(input == a[i])
            return 1;
    }
    return 0;
}