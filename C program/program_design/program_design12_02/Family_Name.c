#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checktwoCharFMname(char *inputStr[], char *twoCharFMname[]);
int checkoneCharFMname(char *inputStr[], char *oneCharFMname[]);

int main()
{
    //system("chcp 65001");
    char *twoCharFMname[] = {"軒轅", "歐陽", "司馬", "司徒", "司空", "司寇", "上官", "尉遲", "羊舌", "第五", "梁丘", "鍾離", "東郭", "公孫", "孟孫", "仲孫", "叔孫", "季孫", "長孫", "慕容", "宇文", "閭丘", "諸葛", "東方", "東門", "西門", "公羊", "夏侯", "万俟", "百里", "端木", "公冶", "皇甫", "呼延", "浮屠", "令狐", "淳于", "即墨", "單于", "南宮", "田丘", "伊能"};
    char *oneCharFMname[] = {"王", "李", "張", "劉", "陳", "楊", "黃", "吳", "趙", "周", "徐", "孫", "馬", "朱", "胡", "林", "郭", "何", "高", "羅", "鄭", "梁", "謝", "宋", "唐", "許", "鄧", "馮", "韓", "曹", "曾", "彭", "蕭", "蔡", "潘", "田", "董", "袁", "于", "余", "葉", "蔣", "杜", "蘇", "魏", "程", "呂", "丁", "沈", "任", "姚", "盧", "傅", "鍾", "姜", "崔", "譚", "廖", "范", "汪", "陸", "金", "石", "戴", "賈", "韋", "夏", "邱", "方", "侯", "鄒", "熊", "孟", "秦", "白", "江", "閻", "薛", "尹", "段", "雷", "黎", "史", "龍", "陶", "賀", "顧", "毛", "郝", "龔", "邵", "萬", "錢", "嚴", "賴", "覃", "洪", "武", "莫", "孔" };
    char inputStr[100];
    char *sep[100];
    char *p;
    while(1)
    {
        printf("請問尊姓大名 (輸入 quit 表示離開本系統):\n");
        fgets(inputStr, sizeof(inputStr), stdin); strtok(inputStr, "\r\n");
        if(!strcmp(inputStr, "quit")) break;
        if(checktwoCharFMname(inputStr, twoCharFMname))
        {
            strncpy(sep, inputStr, 4);
            p = inputStr[5];
            printf("歡迎 %s 同學 %s 的歡迎!\n", sep, *p);
        }
        if(strlen(inputStr)/strlen("一") == 4)
        {
            
        }
            
    }
    printf("感謝使用本系統！\n");
}
int checktwoCharFMname(char *inputStr[], char *twoCharFMname[])
{
    int i;
    char *sep[100];
    strncpy(sep, inputStr, 4);
    for(i=0 ; i<42 ; i++)
    {
        if(!strcmp(sep, twoCharFMname[i]))//相等
            return i;
    }
    return 0;
}
int checkoneCharFMname(char *inputStr[], char *oneCharFMname[])
{

}
/*
"諸葛亮"
"諸","葛","亮"
*/