#include "stdio.h"
#include "string.h"
#include <stdbool.h>

int main(int ac, char **av){

    int i, j;


    int myAsc[128];
    for(i=0;i<128;i++)
      myAsc[i] =0;


    for(i = 1;i<ac;i++){
        for(j = 0;j< strlen(av[i]);j++){
            myAsc[(int)av[i][j]]++;
        }
    }

    for(i=0;i<128;i++){
        printf("%d \n",myAsc[i]);
    }


}