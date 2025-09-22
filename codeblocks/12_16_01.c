#include <stdio.h>
#include <string.h>

int indexOfList(char str[], char *list[], int itemTotal);

typedef struct
{
    char name[30]; // name of the player
    int level; // level of the player
    char skill; // kongfu records which the player has learned
} PlayerData;

int main()
{
    PlayerData player[10];
    char *kungfuName[] = {"鐵頭功\", "旋風地堂腿", "金鐘罩鐵布衫", "鬼影擒拿手", "輕功\水上飄", "大力金剛腿", "獅子吼", "如來神掌"};
    char *p, inputStr[1000];
    int i=0, k;
    FILE *fptr = fopen("playerData_BIG5.txt", "r");
    if (fptr == NULL)
    {
        printf("開檔失敗\n");
        exit(0);
    }
    //printf("123");
    while(fgets(inputStr, sizeof(inputStr), fptr)!=NULL)
    {
        //printf("%s", inputStr);
        strtok(inputStr, "\r\n");
        //printf("123");
        if (!strncmp(inputStr, "name=", strlen("name=")))
        {
            //printf("123");
            p = inputStr + strlen("name=");
            strcpy(player[i].name, p);
        }
        else if(!strncmp(inputStr, "level=", strlen("level=")))
        {
            p = inputStr + strlen("level=");
            player[i].level = atoi(*p);
        }
        else if(!strncmp(inputStr, "[player]", strlen("[player]")))
            i++;
        else
        {
            p = inputStr + strlen("skill=");
            strcpy(player[i].skill, p);
            //printf("123");
        }

        printf("Name: %s\n", player[i].name);
        printf("Level: %d\n", player[i].level);
        //printf("123");
    }
    //int kf = indexOf(inputKungfu, kungfuName, ...);
    fclose(fptr);
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
