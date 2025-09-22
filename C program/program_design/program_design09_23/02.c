#include <stdio.h>

int main()
{
    int n,m,o,p;
    printf("請輸入頭獎號碼：");
    scanf("%d", &n);
    printf("請輸入你的發票號碼：");
    scanf("%d", &m);
    o = m % 100000000;
    if ( o == n )
    {
        printf("恭喜！你中了頭獎！");
    }
    
    else 
    {
        o = m % 10000000;
        p = n % 10000000;
        if ( o == p )
        {
            printf("恭喜！你中了二獎！");
        }

        else
        {
            o = m % 1000000;
            p = n % 1000000;
            if ( o == p )
            {
                printf("恭喜！你中了三獎！");
            }

            else
            {
                o = m % 100000;
                p = n % 100000;
                if ( o == p )
                {
                    printf("恭喜！你中了四獎！");
                }
                else
                {
                    o = m % 10000;
                    p = n % 10000;
                    if ( o == p )
                    {
                        printf("恭喜！你中了五獎！");
                    }
                    else
                    {
                        o = m % 1000;
                        p = n % 1000;
                        if ( o == p )
                        {
                            printf("恭喜！你中了六獎！");
                        }
                        else
                        {
                            printf("抱歉沒有中獎。");
                        }
                    }
                }
            }
        }
    }
}