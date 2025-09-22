#include <stdio.h>
int isInvalidDate(int year, int month, int day);
int isLeapYear(int year);
int main() 
{
    int ti, repeatTimes, year, month, day;
    printf("How many sets of test data: "); scanf("%d",&repeatTimes);
    for (ti = 0; ti < repeatTimes; ti++) 
    {
        printf("\nInput a date (year/month/day): ");
        scanf("%d/%d/%d", &year, &month, &day);
        printf("%d/%d/%d %s a valid date.\n", year, month, day, isInvalidDate(year, month, day) ? "is not" : "is");
    }
    return 0;
}
int isInvalidDate(int year, int month, int day)// true = invaildDate, false = vaildDate
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //int b, c;
    if(month<0 || month > 12 || day <= 0 || day > 31) return 1;
    if(isLeapYear(year) == 1 && month == 2 && day == 29) return 0;
    if (month < 1 && month > 12) return 1;//check month
    if(day > days[month-1]) return 1;//
    return 0;
}
int isLeapYear(int year)
{
    int a;
    if(year % 400 == 0) a = 1;//check year
    else if (year % 100 == 0) a = 0;
    else if (year % 4 == 0) a = 1;
    else a = 0;
    return a;
}
/*
5
2015/-7/23
2015/5/0
2016/2/29
2015/2/29
777/3/6
*/