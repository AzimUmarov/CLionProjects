#include "stdio.h"
#include "string.h"
#include <stdbool.h>

bool isUnique(char c, char* letter, int j){
    for(int i =0;i< j;i++){
        if(letter[i]==c)
            return false;
    }
    return true;

}

int main(int ac, char **av){

    char str[]  = "assddd";

    char letter[26];
    int j = 0;
    for(int i =0;i<strlen(str);i++) {
        if (isUnique(str[i], letter, j))
            letter[j] = str[i];
            j++;
    }
            letter[j]='\0';


    char countC[strlen(letter)][10];

    for(int i =0;i<strlen(letter);i++) {
        int count = 0;
           for(int k =0;k< strlen(str);k++)
               if(letter[i]==str[k])
                   count++;
        sprintf(countC[i],"%c:%d",letter[i],count);

    }

    for(int i = 0;i< strlen(letter);i++)
        printf("%s\n",countC[i]);






}