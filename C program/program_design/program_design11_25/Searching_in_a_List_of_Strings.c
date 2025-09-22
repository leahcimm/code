#include <stdio.h>
#include <string.h>
#define countryTotal 21

int indexOfList(char str[], char *list[], int itemTotal);

int main()
{
    char str[300];
    char *country[countryTotal] = {
	"China",
	"Japan",
	"Korea",
	"India",
	"Indonesia",
	"Malaysia",
	"Singapore",
	"Thailand",
	"Viet Nam",
	"Taiwan",
	"Mexico",
	"Brazil",
	"Canada",
	"USA",
	"the United Kingdom",
	"Italy",
	"Spain",
	"France",
	"Germany",
	"Australia",
	"New Zealand"
    };
    int population[countryTotal] = {
	1425887, 123952, 51816, 1417173, 275501,
	33938, 5976, 71697, 98187, 23893, 127504,
	215313, 38454, 338290, 67509, 59037, 47559,
	64627, 83370, 26177, 5185
    };
    printf("Welcome to the World Population Database!\n");
    printf("\n");
    while( 1 )
    {
        printf("Input a line (\"quit\" to exit): ");
        fgets(str, sizeof(str), stdin); strtok(str, "\r\n");
        if( !strcmp(str, "quit") ) break;
        if( indexOfList(str, country, 21) == -1) 
            printf("Sorry, we cannot find [%s] in our database.\n", str);
        else printf("The population of %s is %d thousands.\n", str, population[indexOfList(str, country, 21)] );
        
		printf("\n");
    }
	printf("Thank you for using World Population Database!");
}
int indexOfList(char str[], char *list[], int itemTotal)
{
    int i;
    for(i=0 ; i<itemTotal ; i++)
    {
        if(!strcmp(str, list[i]))//相等
            return i;
    }
    return -1;
}