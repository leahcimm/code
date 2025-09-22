#include <stdio.h>
#include <time.h>
void printCard(int id);
void shuffling(int a[], int N);

int main ()
{
    srand((unsigned int)time(NULL));
    //system("chcp 65001");
    int id = 0, i, j;
    int a[52];
    char* highRank[4] = {"J", "Q", "K", "A"};
    shuffling(a,52);
    int card[4][13];
    for(i=0 ; i<4 ; i++)
    {
        printf("Player %d: ", i+1);
        for(j=0 ; j<13 ;j++)
        {
            card[i][j] = a[i*13+j];//將a[]分配到4個玩家手中
            printCard(card[i][j]);
        }
        printf("\n");
    }
    while (1)
    {
        printf("\nInput a card ID(type -1 to stop): ");
        scanf("%d", &id); if (id == -1) break;
        printCard(id);
        putchar('\n');
    }
    //return 0;
    while(1)
    {
        int b[5];
        printf("\nInput a card ID(give five ID & type -1 to stop): ");
        int suitCount[4]={0}, rankCount[14]={0};
        for(i=0 ; i<5 ; i++)
        {    
            scanf("%d", &id);if(id == -1) break;
            b[i] = id;
            suitCount[id / 13]++;
            rankCount[id % 13]++;
        }
        if(id == -1) break;
        for(i=0;i<5;i++)
        {
            printCard(b[i]);
        }
        printf("have\n");
        printf("♣(%d) ♦(%d) ♥(%d) ♠(%d)\n",suitCount[0],suitCount[1],suitCount[2],suitCount[3]);
        for(i=0;i<13;i++)
        {
            if(i<10)
                printf("%d(%d) ", i+2, rankCount[i]);
            else
                printf("%s(%d) ", highRank[i-9],rankCount[i]);
        }
    }
}
void printCard(int id)
{
    char* suitSymbol[4] = {"♣", "♦", "♥", "♠"};
    char* highRank[4] = {"J", "Q", "K", "A"};
    if(id%13 <= 8)
        printf("%s%-2d ",suitSymbol[id / 13],id%13+2);
    else
        printf("%s%-2s ",suitSymbol[id / 13],highRank[(id%13) - 9]);
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