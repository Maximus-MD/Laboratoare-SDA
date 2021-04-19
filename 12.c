#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Prima_si_Ultima(char * s)
{
    int i, n;
    s = (char *)malloc(n * sizeof(char *));
    printf("Introduceti sirul:\n");
    gets(s);
    printf("\n");
    for(int i = 0; i < strlen(s); i++){
        if(i == 0){
           printf("Primele si ultimele litere din fiecare cuvint sunt: %c",s[i]);
        }
        if(i == strlen(s) - 1){
           printf("%c",s[i]);
        }
        if(s[i] == ' '){
            printf("%c%c",s[i-1],s[i+1]);
        }
    }
    printf("\n-----------------------------------------------------");
    free(s);
    return s;
}
int main()
{
    char * s;
    Prima_si_Ultima(s);
    return 0;
}
