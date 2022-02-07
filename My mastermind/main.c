#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"



int main(int ac, char **av)
{
      int attempts = 10,countWP= 0, countMP = 0;
      int ret;
      char *code;
      srand(time(0));
      char buf[5];

            if(ac==5){
                code = av[2];
                attempts = atoi(av[4]);
            }
            else if(ac==3)
                code = av[2];
            else {
                for(int i =0;i<4;i++)
                    code[i] = rand()%8+48;
                code[4] = '\0';
            }
            printf("Will you find the secret code?\n---\n");

            for(int i =0;i<attempts;i++){
                printf("Round %d \n>\n", i);
                scanf("%s", buf);
                for(int i =0;i<4;i++){
                    if(buf[i]==code[i])
                        countWP++;
                    else{
                        for(int j =0; j<4;j++)
                            if(code[i]==buf[j])
                                countMP++;
                    }
                }
                printf("Well placed pieces: %d\nMisplaced pieces: %d\n",countWP,countMP);
            }


    //printf("%s, %d \n", code, attempts);
}
