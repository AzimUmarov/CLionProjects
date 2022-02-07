#include "stdio.h"
#include "string.h"
#include <ctype.h>


char* last_word(char* param_1)
{
    char t[45];
    int k = -1,i,c=0;
    for(int i = strlen(param_1)-1;i>-1;i--){
        if(isalpha(param_1[i])){
            t[++k] = param_1[i];
            if(!isalpha(param_1[i-1]))
            c = 1;
        }
        if(!isalpha(param_1[i]) && c)
            break;
    }

    static char word[45];
    for( i =0;i< strlen(t);i++){
        word[i] = t[k];
        k--;
    }
    word[i]='\0';

    return word;

}

int main(){

    char str[] = "\"this        ...       is sparta\"";

    printf("%s", last_word(str));

}


