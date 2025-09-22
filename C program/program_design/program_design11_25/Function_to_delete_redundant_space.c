#include <stdio.h>
#include <string.h>

void delSpace(char str[]);

int main() 
{
    char str;
    char a[] = "Test    string    1";
    char b[] = "   Test string    2   ";
    char c[] = "    ";
    printf("Before:\t[%s]\n\t[%s]\n\t[%s]\n", a, b, c);

    delSpace(a);
    delSpace(b);
    delSpace(c);// Call delSpace() to delete space in str1, str2, and str3 here by yourself        

    printf("\nAfter:\t[%s]\n\t[%s]\n\t[%s]\n", a, b, c);
    return 0;
}
void delSpace(char str[])
{
    //step1
    char *p, *q;
    q = str + strlen(str)-1;
    while( *q == ' ' )
    {
        *q = '\0';
        q--;
    }
    //step2
    p = str;
    q = str;
    while( *q == ' ' )
        q++; //printf("%s", str);
    //step3
    while( q <= str + strlen(str))
    {
        *p = *q;
        if( *p == ' ')
        {
            while( *q == ' ' )
                q++;
            p++;
        }
        else 
        {
            q++;
            p++;
        }
    }
}