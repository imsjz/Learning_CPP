/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 15:52:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    extern const int a; //告诉编译器a在外部
    printf("a = %d\n", a);

    return 0;
}
