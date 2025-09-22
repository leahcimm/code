#include <stdio.h>

int main()
{
    int M,D,beginningDay[12]={20,20,21,21,21,22,23,23,23,23,22,22},zodiacCode,c,k;
    char * zodiacName[12] = {"牡羊", "金牛", "雙子","巨蟹","獅子","處女","天秤","天蠍","射手","摩羯","水瓶","雙魚"};
    printf("請輸入日期 (以 月/日 的格式) : ");
    scanf("%d/%d",&M,&D);
    zodiacCode = (M + 9) % 12;//-3+12
    if(D<beginningDay[M-1])
        zodiacCode = (zodiacCode +11) % 12;
    printf("你是%s座的，星座代碼是 %d。",zodiacName[ zodiacCode ],zodiacCode);

}