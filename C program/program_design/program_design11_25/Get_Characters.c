#include <stdio.h>
#include <string.h>

int toValue( char ch );

int main()
{
    char ch, buffer[100];
    int answer = 0, base, i;
    printf("Please input the base: "); scanf("%d", &base); // get base from keyboard
    printf("Please input a number: ");
    getchar(); // in order to get rid of the newline symbol '\n'
    i = 0;
    while ( (ch = getchar()) != '\n' )
    {
        //printf("%d ",toValue(ch));
        if( toValue(ch) >= 0 && toValue(ch) < base )
        {
            buffer[i] = ch;
            i++;
        }
        else break;
    }
    buffer[i] = '\0'; // terminate the string
    printf("The input number is (%s)%d\n", buffer, base);
    for( i=0 ; i<strlen(buffer) ; i++)
    {
        answer = answer*base + toValue(buffer[i]);
    }//evaluate answer from buffer;
    printf("It is %d in decimal form.\n", answer);
}
int toValue( char ch )
{
    if( ch <= '9' && ch >= '0' )
        return ch-'0';
    else
    {
        if(ch >= 'a' && ch <= 'z')
            return ch - 'a' + 10;
        else return ch - 'A' + 10;
    }
}
/*
8
25048672
16
73e52aC
*/