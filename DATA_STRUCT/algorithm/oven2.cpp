#include <string.h>
#define BUFFER_SIZE 100

void vulnerable_function(char* input) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, input);  // 危險：沒有檢查input長度
}