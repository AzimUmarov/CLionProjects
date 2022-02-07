#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
int main(int ac, char **av){
    char buf[20];
    int ret;

    ret = read(0, buf, 20);
    printf("%s\n", buf);


    printf("%d",ret);
    return 0;

}