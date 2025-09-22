#include <stdio.h>
#include <string.h>

typedef struct
{
    char engName[300];
    char sciName[300];
    int avgLength;
    int avgWeight;
    char environment;
}FishData;

int main()
{
    FishData fish[5]=
    {
        {"Milk Fish", "Chanos chanos", 40, 300, 'S'},
        {"Black King Fish", "Rachycentron canadum", 150, 40000, 'S'},
        {"Grass carp", "Ctenopharyngodon idella", 150, 35000, 'F'},
        {"Gold Head Cichlid", "Aulonocara baenschi", 15, -1, 'F'},
        {"Ocellaris clownfish", "Amphiprion ocellaris", 4, -1, 'S'}
    };

    int i;
    char fishName[300];
    printf("Welcome to the NTOU Marine Education Encyclopedia!\n");
    while(1)
    {
        printf("\nInput the name of fish (\"quit\" to exit): ");
        fgets(fishName, sizeof(fishName), stdin); strtok(fishName, "\r\n");
        if(!strcmp(fishName, "quit")) break;
        for(i = 0 ; i < 5 ; i++)
        {
            if(!strcmp(fish[i].engName, fishName)) break;
        }
        if(i==5) printf("Sorry, we cannot find [%s] in our database.\n", fishName);
        else
        {
            if(fish[i].avgWeight==-1) printf("%s (%s): average length %dcm, %s.\n", fish[i].engName, fish[i].sciName, fish[i].avgLength, (fish[i].environment == 'F')?"freshwater fish":"seawater fish");
            else printf("%s (%s): average length %dcm, average weight %dg, %s.\n", fish[i].engName, fish[i].sciName, fish[i].avgLength, fish[i].avgWeight, (fish[i].environment == 'F')?"freshwater fish":"seawater fish");
        }
    }
    printf("\nThank you for using the NTOU Marine Education Encyclopedia!\n");
}
