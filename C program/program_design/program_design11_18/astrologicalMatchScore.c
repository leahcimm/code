#include <stdio.h>
void getDate(int *y, int *m, int *d);
int getZodiacCode(int m, int d);//zodiacCode = (M + 9) % 12;
int isLeapYear(int *year);
int isInvalidDate(int *year, int *month, int *day);

int main()
{
    //system("chcp 65001");
    int matchScore[12][12]={ // matchScore[girl's zodiac][boy's zodiac]
    90, 75, 82, 47, 94, 65, 85, 70, 99, 58, 88, 79,
    68, 88, 72, 75, 45, 97, 57, 78, 61, 93, 66, 81,
    79, 76, 89, 71, 81, 57, 93, 69, 86, 64, 99, 48,
    52, 82, 78, 89, 61, 84, 66, 92, 70, 87, 74, 97,
    97, 56, 79, 69, 87, 72, 81, 45, 92, 77, 84, 62,
    61, 91, 76, 88, 66, 89, 49, 81, 72, 95, 55, 84,
    85, 74, 98, 58, 88, 77, 90, 71, 80, 47, 95, 64,
    60, 80, 68, 97, 65, 84, 73, 87, 47, 76, 57, 92,
    92, 70, 81, 65, 98, 58, 86, 68, 89, 75, 78, 44,
    43, 97, 70, 80, 59, 92, 51, 85, 64, 88, 74, 77,
    72, 41, 91, 58, 78, 64, 96, 51, 82, 69, 87, 60,
    71, 78, 46, 93, 61, 65, 74, 99, 54, 82, 69, 88 };
    char * zodiacName[12] = {"牡羊", "金牛", "雙子","巨蟹","獅子","處女","天秤","天蠍","射手","摩羯","水瓶","雙魚"};
    int boyYear, boyMonth, boyDay;
    int girlYear, girlMonth, girlDay;

    printf("請輸入男生的生日。\n"); getDate(&boyYear, &boyMonth, &boyDay);
    printf("請輸入女生的生日。\n"); getDate(&girlYear, &girlMonth, &girlDay);

    int boyCode = getZodiacCode(boyMonth, boyDay);
    int girlCode = getZodiacCode(girlMonth, girlDay);

    printf("男生是%s座，女生是%s座。\n", zodiacName[boyCode], zodiacName[girlCode]);
    printf("兩人的速配指數是%d!!!\n", matchScore[girlCode][boyCode]);
}
void getDate(int *y, int *m, int *d)
{
    scanf("%d/%d/%d", y, m, d);
    while(isInvalidDate(y, m, d))
    {
        printf("是不合法日期!\n"); scanf("%d/%d/%d", y, m, d);
    }
}
int getZodiacCode(int m, int d)
{
    int beginningDay[12]={20,20,21,21,21,22,23,23,23,23,22,22}, zodiacCode;
    zodiacCode = (m + 9) % 12;//-3+12
    if(d<beginningDay[m-1])
        zodiacCode = (zodiacCode +11) % 12;
    return zodiacCode;
}
int isInvalidDate(int *year, int *month, int *day)// true = invaildDate, false = vaildDate
{

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(*month<=0 || *month > 12 || *day <= 0 || *day > 31) return 1;//2015/2/29
    if(isLeapYear(year) == 1 && *month == 2 && *day == 29) return 0;
    if (*month < 1 && *month > 12) return 1;//check month
    if(*day > days[*month-1]) return 1;//
    return 0;
}
int isLeapYear(int *year)
{
    int a;
    if(*year % 400 == 0) a = 1;//check year
    else if (*year % 100 == 0) a = 0;
    else if (*year % 4 == 0) a = 1;
    else a = 0;
    return a;
}
/*
2015/2/29
2016/2/30
2016/2/29
2016/4/29
*/
