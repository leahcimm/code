#include <stdio.h>
#include <string.h>

char * strstrL(char *sent, char *list[], int size){
    char * ansp = sent + strlen(sent) -1;
    for(int i = 0 ; i < )
    if(ansp = strstr(sent, list[]))
}

int main()
{
    char sentence1[300] = "�^��1�W�k�j�ͦ��ѱ��F���ڥd�B���]�A�S���f���^�a�A�o�J��1�W�u��ͭ^���v�n�Ψ��W�ȳѪ�3�^��ѱϦo�C";
    char sentence2[300] = "��ڪo�����~�U�b�~�H�ӡA�^�T���F46�H�A�X��y�١A�����������Ӥ����A�u�^���h�F�v�C";
    const int punctTotal = 4;
    char * punct[punctTotal] = {"�u", "�v", "�A", "�C"}, *starp = sentence1;
    int punctLen =strlen(punct[0]);
    char *gotPunct = strstrL(startp, punct[punctTotal], punctLen);
    while(gotPunct != NULL){
        *gotPunct = '\0';
        printf("%s\n", starp);
        starp = starp + punctLen;
    }
}
