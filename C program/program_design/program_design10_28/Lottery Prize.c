#include <stdio.h>
#include <time.h>
void shuffling(int a[], int N);
int checkPrize(int ticket[], int firstPrize[], int special);
int printNum(int firstPrize[], int special);
int checkDuplicate(int first[], int special);

int main() {
    char *prizeName[9] = {"", "General", "Seventh", "Sixth", "Fifth", "Fourth", "Third", "Second", "First"};
    int prize[9] = {0, 400, 400, 1000, 1286, 9781, 32705, 1569878, 19100192};
    int first[6], ticket[6], special, i;

    printf("Input the first-prize numbers: ");
    for (i = 0; i < 6; i++) 
    {
        scanf("%d", &first[i]);
    }
    printf("Input the special number: ");
    scanf("%d", &special);
    printf("Input the numbers on the lottery ticket: ");
    for (i = 0; i < 6; i++) 
    {
        scanf("%d", &ticket[i]);
    }

    int prizeCode = checkPrize(ticket, first, special);
    if (prizeCode > 0) printf("You have won the %s Prize which is NT$%d!!\n", prizeName[prizeCode], prize[prizeCode]);
    else printf("You did not win any prize.\n");
    
    printf("\n[Random similation for 5 times]\n");
    for(int j = 0 ; j < 5 ; j++)
    {
        printNum(first, special);
        printf("\nThe first-prize numbers are ");
        for(i = 0 ; i < 6 ; i++)
        {
            printf("%d ", first[i]);
        }
        printf("\nThe special number is %d\n", special);
        int a;
        printNum(ticket,a);
        printf("Your ticket numbers are ");
        for(i = 0 ; i < 6 ; i++)
        {
            printf("%d ", ticket[i]);
        }
        prizeCode = checkPrize(ticket, first, special);
        if (prizeCode > 0) printf("\nYou have won the %s Prize which is NT$%d!!\n", prizeName[prizeCode], prize[prizeCode]);
        else printf("\nYou did not win any prize.\n");
    }
    return 0;
    /*
    7 17 34 8 10 36
    43
    43 7 36 10 6 34
    */
}
void shuffling(int a[], int n)
{
    for(int i=0;i<n;i++)
        a[i]=i;
    for(int i=0 ; i<n ;i++)
    {
        int k = rand() % (n-1);
        int l = rand() % (n-1);
        int t = a[k];
        a[k] = a[l];
        a[l] = t;
    }
}
int checkPrize(int ticket[], int firstPrize[], int special)
{
    int i, j, specialcount = 0, ticketcount = 0;
    for(i = 0 ; i < 6 ; i++)
    {
        for(j = 0 ; j < 6 ; j++)
        {
            if(ticket[i] == firstPrize[j])
                ticketcount++;
        }
    }
    for(i = 0 ; i < 6 ; i++)
    {
        if(ticket[i] == special)
            specialcount++; break;
    }
    
    if(ticketcount == 6) return 8;
    else if(ticketcount == 5 && specialcount ==1) return 7;
    else if(ticketcount == 5 && specialcount ==0) return 6;
    else if(ticketcount == 4 && specialcount ==1) return 5;
    else if(ticketcount == 4 && specialcount ==0) return 4;
    else if(ticketcount == 3 && specialcount ==1) return 3;
    else if(ticketcount == 2 && specialcount ==1) return 2;
    else if(ticketcount == 3 && specialcount ==0) return 1;
    else return 0;
}
int printNum(int firstPrize[], int special)
{
    while(1)
    {
        int special = rand() % 48 +1;
        for(int i = 0 ; i < 6 ; i++)
        {
            int k = rand() % 48 + 1;
            firstPrize[i] = k;
        }
        if(checkDuplicate(firstPrize, special) > 0) continue;
        else break;
    }
}
int checkDuplicate(int first[], int special)
{
    int i, j, dup = 0;
    for(i = 0 ; i < 6 ; i++)
    {
        for(j = 0 ; j < 6 ; j++)
        {
            if(first[j] == special)
                dup++; break;
            if(first[i] == first[j])
                dup++; break;
        }
    }
    if(dup > 0) return 1;
    else return 0;
}