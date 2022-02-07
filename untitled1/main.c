#include "stdio.h"

void hello(int* n){
    n = 20;
    printf("%i \n", n);

}

int main(){

    int n = 10;

    printf("%d \n", n);
    hello(&n);
    printf("%d \n", n);


    //printf("%d \n", n);

}