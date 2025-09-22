#include <stdio.h>
#include <string.h>

typedef struct { int year, month, day; } DateData;
typedef struct { int seatNo; char name[20]; DateData birthdate; } StudentInfo;

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
    StudentInfo S[100];
    char *mon[13]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
    int i, students, Lr, Ur;
    printf("How many students? "); scanf("%d", &students); if (getchar() == '\r') getchar();
    for( i = 0 ; i < students ; i++)
    {
        printf("student[%d].seatNo: ", i); scanf("%d", &S[i].seatNo); if (getchar() == '\r') getchar();
        printf("student[%d].name: ", i); scanf("%s", &S[i].name); if (getchar() == '\r') getchar();
        printf("student[%d].birthdate: ", i); scanf("%d/%d/%d", &S[i].birthdate.year, &S[i].birthdate.month, &S[i].birthdate.day); if (getchar() == '\r') getchar();
    }
    printf("Lower range: "); scanf("%d", &Lr); if(getchar() == '\r') getchar();
    printf("Upper range: "); scanf("%d", &Ur); if(getchar() == '\r') getchar();
    int YoungestIndex;
    YoungestIndex = Lr;
    for( i = Lr ; i < Ur ; i++)
    {
        int result = datecmp(S[YoungestIndex].birthdate, S[i+1].birthdate);
        //if(result == 1) YoungestIndex = i+1;
        if(result == -1) YoungestIndex = i+1;
        //YoungestIndex = i;
    }
    printf("The youngest student from student[%d] to student[%d] is:\n", Lr, Ur);
    printf("%s, No. %d, whose birthday is %s %d.\n", S[YoungestIndex].name, S[YoungestIndex].seatNo, mon[S[YoungestIndex].birthdate.month], S[YoungestIndex].birthdate.day);
}