#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int level;
    char name[100];
    int exp;
    int health;
    int mana;
    int speed;
    int attack;
} PlayerData;

typedef struct 
{
    char type[100];
    int health;
    int speed;
    int attack;
    int proExp;
} MonsterData;

//BASIC
void initialPlayer(PlayerData *p);
void initialMonster(MonsterData *m);
void pirntPlayerData(PlayerData p);

void attack_P2M(int p, int *m);
void attack_M2P(int *p, int m);

#define monsterTotal 3

int main()
{
    system("chcp 65001");
    srand((unsigned int)time(NULL));
    PlayerData player;
    MonsterData monster[monsterTotal];
    int i;

    initialPlayer(&player);
    for(i = 0 ; i < monsterTotal ; i++)
        initialMonster(&monster[i]);
    for(i = 0 ; i < monsterTotal ; i++)
        pirntPlayerData(player);
        /*if(monster[i].speed > player.speed)
            attack_M2P(monster, &player);
        while(player.health > 0 || monster[i].health > 0)
        {
            attack_P2M(player, &monster);
            if(monster[i].health > 0)
                attack_M2P(monster, &player);
        }*/
}
void initialPlayer(PlayerData *p)
{
    char inputName[100];
    printf("請輸入玩家的名字：");
    fgets(inputName, sizeof(inputName), stdin); strtok(inputName, "\r\n");
    p->level = 0;
    strcpy(p->name, inputName);
    p->exp = 0;
    p->health = rand()%51 + 350;
    p->mana = rand()%21 + 100;
    p->speed = rand()%16 + 35;
    p->attack = rand()%21 + 40;
}
void initialMonster(MonsterData *m)
{
    
    m->health = rand()%51 + 350;
    m->speed = rand()%16 + 35;
    m->attack = rand()%21 + 40;
}
void pirntPlayerData(PlayerData p)
{
    printf("%s\n", p.name);
    printf("等級 %d, 體力 %d, 速度 %d, 攻擊力 %d, 經驗值 %d\n", p.level, p.health, p.speed, p.attack, p.exp);
}
//草帽小子