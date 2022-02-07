#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}


void my_putstr(char *param_1)
{
    for(int i = 0;param_1[i] != '\0';i++){
        my_putchar(param_1[i]);
    }
}

char *mstr(char *str){
    int i;
    int len = 0;
    char c;
    if (!str)
        return NULL;
    while(str[len] != '\0'){
        len++;
    }
    for(i = 0; i < (len/2); i++)
    {
        c = str[i];
        str [i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return str;
}


char* printp(void *thing) {
    uintptr_t j = (uintptr_t) thing;
    char lst[(sizeof j * CHAR_BIT + 3)/ 4 + 1]; // Size needed to print in base 16
    char *p = &lst[sizeof lst] - 1;
    *p = '\0';
    do {
        p--;
        *p = "0123456789abcdef"[j%16];
        j /= 16;
    } while (p > lst);
    char *r;
    r= (char*)malloc(28*sizeof(char*));
    r[0] = '0';
    r[1] = 'x';
    for(int i = 2; p[i] !='\0'; i++){
        r[i] = p[i+2];
    }
    return r;

}

char * printNumber(long long i, char *strout, int b){

    char *str = strout;
    if(i==0){
        *strout = '0';
        strout[1] = '\0';
        return 0;
    }
    int digit, sign = 0;
    if (i < 0) {
        sign = 1;
        i *= -1;
    }
    while(i) {
        digit = i % b;
        *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
        i = i / b;
        str ++;
    }
    if(sign)
        *str++ = '-';

    *str = '\0';
    mstr(strout);
    return strout;
}

int my_printf(char * str, ...){
    va_list c;
    int i = 0, j = 0;
    char buff[1000] = {0}, tmp[200];
    char *strarg;

    va_start(c, str);
    while (str && str[i] != '\0') {
        if(str[i] == '%'){
            i++;
            switch (str[i]) {
                case 'c': {
                    buff[j] = (char) va_arg(c, int);
                    j++;
                    break;
                }
                case 'u':{
                    long long i = va_arg(c, int);
                    long long t = 4294967296;
                    if(i<0){
                        i = t + i;
                    }
                    printNumber(i, tmp, 10);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'd':
                case 'i':{
                    printNumber(va_arg(c, int), tmp, 10);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'p': {
                    strarg = printp(va_arg( c, char* ));
                    strcpy(&buff[j], strarg);
                    j += strlen(strarg);
                    break;
                }
                case 'x': {
                    printNumber(va_arg(c, int), tmp, 16);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'o': {
                    printNumber(va_arg(c, int), tmp, 8);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 's': {
                    strarg = va_arg(c, char* );
                    if(!strarg || !*strarg) {
                        strcpy(&buff[j], "(null)");
                        j += 6;
                    }
                    else {
                        strcpy(&buff[j], strarg);
                        j += strlen(strarg);
                    }
                    break;
                }
                default:{
                    my_putstr("Error input !\n");
                    return j;
                }
            }
        } else {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    write(STDOUT_FILENO, buff, j);
    va_end(c);
    return j;
}

int main(){
    int p =0;
    int len =  my_printf("%p!\n",&p);
    printf("\n%i\n",len);

    return 0;
}



/*

int main () {
//    int len1 = printf("NULL STRING %s!\n", (char*)NULL);
//    int len2 = my_printf("NULL STRING %s!\n", (char*)NULL);
//    printf("%i\n%i\n", len1, len2);
//    if (6 == my_printf("%u\n!", -1337))
//        my_printf("UDEC ok!\n"); // q 19/23
//
//    if (18 == my_printf("%d - %d - %d!\n", 2048, 0, -1337))
//        my_printf("NUMS OK!\n"); // q 16/23
//
//    printf("\n\n\n\n");
//
//    if (6 == printf("%u\n!", -1337))
//        printf("UDEC ok!\n"); // q 19/23
//
//    if (18 == printf("%d - %d - %d!\n", 2048, 0, -1337))
//        printf("NUMS OK!\n"); // q 16/23


   int y =  my_printf("%u\n!", -1337);
    printf("\n\n\n\n");
   int y2 =  printf("%u\n!", -1337);

    printf("\n\n\n\n");
    printf("%i\n %i\n",y, y2);
    return 0;
}



#include <assert.h>
int main () {
    if (13 == my_printf("Hello world!\n"))
        my_printf("OK 1!\n");

    if (3 == my_printf("%c!\n", 'H'))
        my_printf("OK 2!\n");

    if (7 == my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'))
        my_printf("OK! 3\n");

    if (17 == my_printf("Hello %s!\n", "QWASAR.IO"))
        my_printf("OK 4!\n");

    if (17 == my_printf("Hello %s %s!\n", "Mr", "Gaetan"))
        my_printf("OK 5!\n");

    if (20 == my_printf("NULL STRING %s!\n", (char*)NULL))
        my_printf("NULL OK!\n");

    if (6 == my_printf("%d!\n",1337))
        my_printf("NUM OK!\n");

    if (18 == my_printf("%d - %d - %d!\n", 2048, 0, -1337))
        my_printf("NUMS OK!\n"); // q 16/23

    if (5 == my_printf("%o!\n", 100))
        my_printf("Octal ok!\n"); // q 17/23

    if (6 == my_printf("%u\n!", -1337))
        my_printf("UDEC ok!\n"); // q 19/23

    if (3 == my_printf("%x!\n", 14))
        my_printf("HEX ok!\n");//21/23

    int var  = 69;
    my_printf("%p\n", &var);
    if (16 == my_printf("%p!\n", &var))
        my_printf("PTR OK!\n");

    return 0;
}
 */