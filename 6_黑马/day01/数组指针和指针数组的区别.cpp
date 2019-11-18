/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 22:02:38
 */
#include <iostream>

using namespace std;

void test01(){

    
    //对一维数组的应用
    int *a[5]; //指针数组 array of pointers
    int (*b)[5]; // 数组指针 a pointer to an array
    int c[5] = {1,2,3,4,5};
    //把数组分配给两者
    b = &c; //这里要取c的地址
    for(int i = 0; i < 5; ++i){
        a[i] = &c[i];
    }
    int *p = c;
    cout << sizeof(p) << endl;
    cout << sizeof(c) << endl;
    //随机查看结果
    cout << *a[1] << endl; //输出2就对
    cout << (*b)[1]  << endl;
    

    //对二维数组的应用
    int arr[3][4];
    int* pArray[3]; //指针数组
    int (*aPointer)[4]; //数组指针

    //赋值
    for(int i = 0; i < 4; ++i){
        pArray[i] = arr[i];
    }

    aPointer = arr; 
    aPointer++; //从arr[0][] 到arr[1][]


}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
