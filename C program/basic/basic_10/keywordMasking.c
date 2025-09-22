#include <stdio.h>
#include <string.h>

void keywordMasking(char * sentence, char * keyword)
{
    int i;
    char maskStr[strlen(keyword)], *p = sentence;
    for(i = 0 ; i < strlen(keyword) ; i++)
        maskStr[i] = '#';
    while(1)
    {
        p = strstr(sentence, keyword);
        if(p==NULL) break;
        strncpy(p, maskStr, strlen(keyword));//用strncpy可以限制讀多少
    }
}

int main() {
    char sentence[1000], keyword[1000];
    int ti, repeatTimes;
    printf("How many sets of test data: "); scanf("%d", &repeatTimes); if(getchar() == '\r') getchar(); // get repeatTimes from keyboard
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput a sentence: ");
        fgets(sentence, sizeof(sentence), stdin); strtok(sentence, "\r\n");
        printf("Input a keyword: ");
        //scanf("%s", keyword); if(getchar() == '\r') getchar();
        fgets(keyword, sizeof(keyword), stdin); strtok(keyword, "\r\n"); // or fgets(??)
        keywordMasking(sentence, keyword);
        printf("The masked sentence is [%s]\n", sentence);
    }
    return 0;
}
/*
2
Oh my gosh! Can you say gosh?
gosh
I don't want to see any "an" in the sentence.
an
*/