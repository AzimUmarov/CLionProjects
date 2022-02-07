#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

string_array* my_split(char* param_1, char* param_2) {

    char str[10][10];
    int j = 0, k;
    for(int i =0; i < strlen(param_1);i++){
        k = 0;
        while(param_1[i] != param_2[0])
            str[j][k++] = param_1[i++];
        str[j][k] = '\0';
        j++;
    }

    string_array* res = (string_array*)malloc(10 * sizeof(string_array));
    res->array = malloc(sizeof(char) * (strlen(param_1)+1));
    res->size = j;

    for(int i =0; i < j;i++)
        res->array[i] = str[i];


    printf("%s\n", res->array[0]);
    printf("%s\n", res->array[1]);
    printf("%s\n", res->array[2]);

    return res;
}

int main(){

     string_array* t = my_split("abc def gh-!",  " ");

    printf("%s\n",t->array[1]);
    printf("%s\n", t->array[2]);


}