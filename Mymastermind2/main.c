#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"

void my_putchar(char c) {
    write(1, &c, 1);
}


void my_putstr(char *param_1)
{
    for(int i = 0;param_1[i] != '\0';i++)
        my_putchar(param_1[i]);
}




int checkRI(char *code, char*buf){
    for(int i = 0;i < 4; i++)
        if(buf[i]<48 || buf[i] >57)
            return 0;
    return 1;
}



void myMastermind(char *code, int attempts){

    int i,WP = 0, MP = 0;

    my_putstr("Will you find the secret code?\n---\n");

    for( i =0;i<attempts;i++) {

        printf("Round %d \n", i);
        char buf[20];
        int ret;
        while(1){
            my_putstr(">");
            ret = read(0,buf, 20);//scanf("%s", buf);
            if (checkRI(code, buf))
                break;
                my_putstr("Wrong input!\n");
        }
        for(int j =0;j < 4;j++){
            if(code[j]==buf[j])
                WP++;
            else
                for(int k = 0;k<4;k++)
                    if(code[j] == buf[k])
                        MP++;
        }
        if(WP == 4) {
            my_putstr("Congratz! You did it!\n");
            i =-1;
            break;
        }

            printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\n", WP, MP);


         WP = 0, MP =0;
    }
    if(i!=-1)
        my_putstr("You lose it!\n");

}



int main(int ac, char **av)
{

    int attemps = 10, r =1;
    char *code;
    srand(time(0));

    for(int i =1;i<ac;i++){
        if(av[i][1] == 'c') {
            code = av[i + 1];
             r = 0;
        }
        if(av[i][1] == 't')
            attemps = atoi(av[i+1]);
    }
    if(r){
        for (int i = 0; i < 4; i++) {
            code[i] = rand() % 8 + 48;
        }
        code[4] = '\0';
    }
        myMastermind( code,attemps);


    return 0;

}
