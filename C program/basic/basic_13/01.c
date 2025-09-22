#include <stdio.h>
#include <string.h>

int main()
{
    int records, year[10], month[10], day[10], donation[10];
    char inputStr[300], name[10][50];
    printf("Please input the number of donation records: "); scanf("%d", &records); if(getchar() == '\r') getchar();
    printf("Please input the donor's name, donation date (year/month/day), and donation amount in one line.\n");
    //get records
    for(int i = 0 ; i<records ; i++) {
        printf("Record %d: ", i+1);
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");
        sscanf(inputStr, "%s %d/%d/%d %d", name[i], &year[i], &month[i], &day[i], &donation[i]); //sscanf
    }
    //find the max weight
    int weight=0;
    for(int i = 0 ; i<records ; i++) {
        if(weight < strlen(name[i]))
            weight = strlen(name[i]);
    }
    //print the records
    for(int i = 0 ; i<records ; i++) {
        printf("%04d/%02d/%02d [%-*s] $%7d\n", year[i], month[i], day[i], weight, name[i], donation[i]);
    }
}