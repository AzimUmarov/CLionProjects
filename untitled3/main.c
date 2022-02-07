#include <stdio.h>
#include "string.h"
#include "ctype.h"

char*  last_word(char* param_1)
{
    int i, b;
    int j=0;
    for( i = strlen(param_1)-1;i>=0;i--){
        if(isalpha(param_1[i]))
            b = i;

        if(b && isalpha(param_1[i]))
            j++;
        else if(b)
            break;
    }
    static char word[46];
    int d =0;
    for(i =b-j;i>b;i++){
        word[d] = param_1[i];
        d++;
    }
    //word[0] = 'o';
    //word[1] = 's';

    return word;


}

int main() {

    char str[] ="Salom salo";

    printf("%s", last_word(str));


    return 0;
}
