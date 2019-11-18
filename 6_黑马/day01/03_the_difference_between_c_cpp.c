/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 13:04:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.全局变量检测增强
int a;
int a = 10;

int getRectS(w, h){

}

void test(){
    getRectS(10, 20, 10);
    char *p = malloc(sizeof(64));
}

struct person{
    int myage;
    //void plusAge(); //C语言不可以加函数
};

void test06(){
    int a = 10;
    int b = 20;

    printf("ret = %d\n", a > b ? a : b);
    *(a > b ? &a : &b) = 100;
}

//const增强
const int m_A = 10; //此变量在全局常量区，不可以更改
//const int m_A = 10; //此变量在全局常量区，不可以更改
void test07(){

    const int m_B = 20;

    //1. 可以通过指针修改m_B的值
    int *p = (int *)&m_B;
    *p = 30;
    printf("m_B = %d\n", m_B);

    // int *p_a = &m_A;
    // *p_a = 40; //更改会出现段错误
    // printf("m_a = %d\n", m_A);

    int size = 3;
    //int arr[size]= {1,2,3}; //c不让用变量作为数组的参数
}



int main(int argc, char *argv[]){

    struct person p; //必须使用struct关键字
    //bool flag; //c语言中没有bool类型


    test07();
    return 0;
}
