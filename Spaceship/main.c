#include "stdio.h"
#include "stdlib.h"
/*
char* my_spaceship(char* param_1)
{
    if(param_1 == NULL)
        return 0;

    char faceup[4][6] = {"left","up","right","down"};
    char f = 1;
    int x =0, y =0;

    for(int i =0; param_1[i] != '\0'; i++){
        if(param_1[i] == 'A'){
            if(f == 0)        x--;
            if(f == 1)        y--;
            if(f == 2)        x++;
            if(f == 3)        y++;
        }

        if(param_1[i] == 'L')          f--;
        if(param_1[i] == 'R')          f++;

        f = f%4;
    }

    if(f<0)        f = f*(-1)+2;

    static char str[38];

    sprintf(str, "{x: %d, y: %d, direction: '%s'}", x, y, faceup[f]);

    return str;


}
 */

char* my_spaceship(char* param_1)
{


    char faceup[4][6] = {"left","up","right","down"};
    char f = 1;
    int x =0, y =0;

    for(int i =0; param_1[i] != '\0'; i++){
        if(param_1[i] == 'A'){
            if(f = 0)        x--;
            if(f = 1)        y--;
            if(f = 2)        x++;
            if(f = 3)        y++;
        }

        if(param_1[i] == 'L')          f--;
        if(param_1[i] == 'R')          f++;

        f = f%4;
    }

    if(f<0)        f = f*(-1)+2;

    static char str[38];

    sprintf(str, "{x: %d, y: %d, direction: '%s'}", x, y, faceup[f]);

    return str;


}

int main(){
    char p[] = "RAALALL";

    char *str = my_spaceship(&p);

    printf("%s \n",my_spaceship(&p));

    int x;
    scanf("%d",&x);



}