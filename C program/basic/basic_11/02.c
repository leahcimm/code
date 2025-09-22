#include <stdio.h>
#include <string.h>

typedef struct { int year, month, day; } DateData;
void getdate(DateData *d)
{
    scanf("%d/%d/%d", &d->year, &d->month, &d->day); if (getchar() == '\r') getchar();
} // or DateData getdate() {...}
int datecmp(DateData date1, DateData date2)
{
    if( date1.year > date2.year ) return 1;
    else if ( date1.year < date2.year ) return -1;
    else
    {
        if( date1.month > date2.month ) return 1;
        else if ( date1.month < date2.month ) return -1;
        else
        {
            if( date1.day > date2.day ) return 1;
            else if ( date1.day < date2.day ) return -1;
            else return 0;
        }
    }
}
int main()
{
    DateData myDate1, myDate2;
    int ti, repeatTimes, rpTimes;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes); if (getchar() == '\r') getchar(); // get repeatTimes from keyboard
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput the first date (year/month/day): ");
        getdate(&myDate1); // or ??? = getdate();
        printf("Input the second date (year/month/day): "); // and then, input the second date
        getdate(&myDate2);
        int result = datecmp(myDate1, myDate2);
        printf("%d-%02d-%02d ", myDate1.year, myDate1.month, myDate1.day); // print first date
        if (result == 1) printf(">");
        else if (result == -1) printf("<");
        else printf("=");
        printf(" %d-%02d-%02d", myDate2.year, myDate2.month, myDate2.day); // print second date
        printf("\n");
    }
    return 0;
}
/*
5
2013/12/5
2015/1/2
2012/4/1
2012/3/18
2000/5/31
2000/5/31
1987/7/7
1987/7/17
2/2/2
1/1/1
*/