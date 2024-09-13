#include <stdio.h>

int main(void)
{
    int word = 0xDEADBEEF;
    int *pword = &word;

    printf("Word: 0x%X\n", word);
    printf("PWord: 0x%X\n", *pword);

    char *pchar = (char *) pword;
    char num2 = 0xDE;
    char *pchar2 = &num2;
    unsigned int num3 = (unsigned int) num2;

    printf("PChar: 0x%X\n", *pchar);
    printf("PChar + 1: 0x%X\n", *(pchar+1) );
    printf("PChar + 2: 0x%X\n", *(pchar+2) );
    printf("PChar + 3: 0x%X\n", *(pchar+3) );
    printf("num2: 0x%X\n", *(pchar2) );
    printf("num3: 0x%X\n", num3 );
}
