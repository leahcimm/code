#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checktwoCharFMname(char *inputStr[], char *twoCharFMname[]);
int checkoneCharFMname(char *inputStr[], char *oneCharFMname[]);

int main()
{
    system("chcp 950");
    char *twoCharFMname[] = {"�a��", "�ڶ�", "�q��", "�q�{", "�q��", "�q�F", "�W�x", "�L��", "�Ϧ�", "�Ĥ�", "��C", "����", "�F��", "���]", "�s�]", "��]", "���]", "�u�]", "���]", "�}�e", "�t��", "�[�C", "�Ѹ�", "�F��", "�F��", "���", "����", "�L�J", "�E�S", "�ʨ�", "�ݤ�", "���M", "�Өj", "�I��", "�B�O", "�O��", "�E�_", "�Y��", "��_", "�n�c", "�ХC", "���"};
    char *oneCharFMname[] = {"��", "��", "�i", "�B", "��", "��", "��", "�d", "��", "�P", "�}", "�]", "��", "��", "�J", "�L", "��", "��", "��", "ù", "�G", "��", "��", "��", "��", "�\\", "�H", "��", "��", "��", "��", "�^", "��", "��", "��", "��", "��", "�K", "�_", "�E", "��", "��", "��", "Ĭ", "�Q", "�{", "�f", "�B", "�H", "��", "��", "�c", "��", "��", "��", "�Z", "��", "��", "�S", "�L", "��", "��", "��", "��", "��", "��", "�L", "��", "��", "�J", "�Q", "��", "�s", "��", "��", "��", "�F", "��", "��", "�q", "�p", "��", "�v", "�s", "��", "�P", "�U", "��", "�q", "��", "��", "�U", "��", "�Y", "��", "��", "�x", "�Z", "��", "��" };
    char inputStr[100];
    char sep1[100];
    char sep2[100];
    char sep12[100];
    char *p;

    while(1)
    {
        int i, count=0;
        printf("\n�аݴL�m�j�W (��J quit ������}���t��):\n");
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");
        if(!strcmp(inputStr, "quit")) break;
        //printf("%s\n", inputStr);
        strncpy(sep1, inputStr, 2);
        sep1[2]='\0';

        strncpy(sep2, inputStr+2, 2);
        sep2[2]='\0';

        strncpy(sep12, inputStr, 2*strlen("�@"));
        sep12[4]='\0';
        int k=0;
        for(i=0 ; i<42 ; i++)
            if(!strcmp(sep12, twoCharFMname[i]))
            {
                printf("�w�� %s �P�� %s ���w��!\n", sep12, inputStr+4);
                k++;
            }
        if(k==1) continue;

        if(strlen(inputStr)/strlen("�@") == 4)
        {
            printf("�w�� %s �P�� %s ���w��!\n", sep12, inputStr+4); continue;
        }

        for(i=0 ; i<100 ; i++)
        {
            if(!strcmp(sep1, oneCharFMname[i]))
                count++;
            if(!strcmp(sep2, oneCharFMname[i]))
                count++;
        }
        if(count == 2)
        {
            int onetwo;
            printf("�аݱz�m (1) %s �٬O (2) %s\n", sep1, sep12);
            scanf("%d", &onetwo); if(getchar() == '\r') getchar();
            if(onetwo == 1)
                printf("�w�� %s �P�� %s ���w��!\n", sep1, inputStr+2);
            else
                printf("�w�� %s �P�� %s ���w��!\n", sep12, inputStr+4);
        }
        else
            printf("�w�� %s �P�� %s ���w��!\n", sep1, inputStr+2);
    }
    printf("�P�¨ϥΥ��t�ΡI\n");
}
int checktwoCharFMname(char *inputStr[], char *twoCharFMname[])
{
    int i;
    char sep[100];
    strncpy(sep, inputStr, 2*strlen("�@"));
    //printf("%s\n", sep);printf("%s\n", inputStr);
    for(i=0 ; i<42 ; i++)
    {

        if(!strcmp(sep, twoCharFMname[i]))//�۵�
            return 1;
    }
    return 0;
}
int checkoneCharFMname(char *inputStr[], char *oneCharFMname[])
{

}
/*
�Ѹ��G
�P��
�P�l��
���i���T
���i�T
1
���i�T
2
*/
