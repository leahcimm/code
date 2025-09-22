#include <stdio.h>
#include <string.h>

int indexOfList(char *str[], char *list[], int itemTotal);

int main()
{
    char document[]="National Taiwan Ocean University was originally established in 1953 as a junior college for the study of maritime science and technology.\nAfter eleven years, in 1964, we became a maritime college which offered bachelor's and master's degrees in various fields of maritime studies. During this period, funds for running the college came from the Taiwan Provincial Government of the Republic of China.\nIn 1979 the national government took over the funding and we became the National Maritime College. After another decade, in 1989, the college grew into a full-fledged university, National Taiwan Ocean University (NTOU).";
    char *wordlist[300], *p;
    int wTotal = 0, frequency[300]={0};
    p = strtok(document, " ,.\n");
    while(p != NULL)
    {
        int k = indexOfList(p, wordlist, wTotal);
        if( k != -1 )
            frequency[k]++;
        else
        {
            wordlist[wTotal] = p;
            frequency[wTotal] = 1;
            wTotal++;
        }
        p = strtok(NULL, " ,.\n");
    }
    for(int i = 0 ; i<wTotal ; i++)
    {
        printf("%-12s %d\n", wordlist[i], frequency[i]);
    }
}

int indexOfList(char *str[], char *list[], int itemTotal)
{
    int i;
    for(i=0 ; i<itemTotal ; i++)
    {
        if(!stricmp(str, list[i]))//¬Ûµ¥
            return i;
    }
    return -1;
}
