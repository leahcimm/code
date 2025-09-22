#include <stdio.h>
#include <string.h>

char * strstrL(char *sent, char *list[], int size){
    char * ansp = sent + strlen(sent) -1;
    for(int i = 0 ; i < )
    if(ansp = strstr(sent, list[]))
}

int main()
{
    char sentence1[300] = "英國1名女大生有天掉了提款卡、錢包，沒錢搭車回家，卻遇到1名「街友英雄」要用身上僅剩的3英鎊解救她。";
    char sentence2[300] = "國際油價今年下半年以來，跌幅高達46％，幾近腰斬，但物價仍漲個不停，「回不去了」。";
    const int punctTotal = 4;
    char * punct[punctTotal] = {"「", "」", "，", "。"}, *starp = sentence1;
    int punctLen =strlen(punct[0]);
    char *gotPunct = strstrL(startp, punct[punctTotal], punctLen);
    while(gotPunct != NULL){
        *gotPunct = '\0';
        printf("%s\n", starp);
        starp = starp + punctLen;
    }
}
