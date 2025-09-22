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

void attack_P2M(PlayerData p, MonsterData *m);
void attack_M2P(PlayerData *p, MonsterData m);

#define monsterTotal 3

int main()
{
    system("chcp 950");
    srand((unsigned int)time(NULL));
    PlayerData player;
    MonsterData monster[monsterTotal];
    int i;

    initialPlayer(&player);
    for(i = 0 ; i < monsterTotal ; i++)
        initialMonster(&monster[i]);
    for(i = 0 ; i < monsterTotal ; i++)
    {
        pirntPlayerData(player);
        printf("\n�I��@���b�~�H�I\n");
        if(monster[i].speed > player.speed)
            attack_M2P(&player, monster[i]);
        while(player.health > 0 && monster[i].health > 0)
        {
            attack_P2M(player, &monster[i]);
            if(monster[i].health > 0)
                attack_M2P(&player, monster[i]);
        }
        if(player.health <= 0)
        {
            printf("��U�p�l���F�C");
            break;
        }
        else
        {
            player.exp += monster[i].proExp;
            printf("�b�~�H���F�C\n��U�p�l��o�g��� %d�C\n", monster[i].proExp);
        }
    }
}
void initialPlayer(PlayerData *p)
{
    char inputName[100];
    printf("�п�J���a���W�r�G");
    fgets(inputName, sizeof(inputName), stdin); strtok(inputName, "\r\n");
    p->level = 1;
    strcpy(p->name, inputName);
    p->exp = 0;
    p->health = rand()%51 + 350;
    p->mana = rand()%21 + 100;
    p->speed = rand()%16 + 35;
    p->attack = rand()%21 + 40;
}
void initialMonster(MonsterData *m)
{

    m->health = rand()%21 + 150;
    m->speed = rand()%16 + 35;
    m->attack = rand()%11 + 20;
    m->proExp = 15;
}
void pirntPlayerData(PlayerData p)
{
    printf("\n%s\n", p.name);
    printf("���� %d, ��O %d, �t�� %d, �����O %d, �g��� %d\n", p.level, p.health, p.speed, p.attack, p.exp);
}
void attack_P2M(PlayerData p, MonsterData *m)
{
    printf("%s�����A�y���b�~�H���� %d �I�C\n", p.name, p.attack);
    m->health = m->health - p.attack;
}
void attack_M2P(PlayerData *p, MonsterData m)
{
    printf("�b�~�H�����A�y��%s���� %d �I�C\n", p->name,m.attack);
    p->health = p->health - m.attack;
}
//��U�p�l
