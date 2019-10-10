/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 17:08:32
 */
#include <iostream>

using namespace std;

void test01(){

    //给数组建立引用
    int arr[10];
    for (int i = 0; i < 10; ++i){
        arr[i] = i+1;
    }
    int (&myarr)[10] = arr;
    for(int i = 0; i < 10; ++i){
        cout << myarr[i] << endl;
    }

    typedef int ARRAY[10];
    ARRAY &tmyarr = arr;
    for(int i = 0; i < 10; ++i){
        cout << tmyarr[i] << endl;
    }
}

int &func(){


    static int a = 10;

    return a;
}

void test02(){

    int &ret = func();
    ret = 20;
    cout << ret << endl;
}

//引用的本质：指针常量  int &ref = val; // ===> int* const ref = val;

void test03(int &ref){ //发现是引用，编译器转换为 int* const ref
    ref = 100; //等价于*ref = 100;
}

//# 指针的用法
// 1. 指针引用
struct Person{
    int age;
};

//C语言的写法
void allocateMemory(Person **person){
    *person = (Person*)malloc(sizeof(Person));
    (*person)->age = 200;
}

//利用指针引用开辟空间
void allocateMemoryRef(Person* &person){
    person = (Person*)malloc(sizeof(Person));
    person->age = 300;
}


void test04(){

    //指针用法
    Person *p = NULL;
    allocateMemory(&p);
    cout << "age: " << p->age << endl;
    free(p);

    //cpp指针引用的写法
    cout << "_______________" << endl;
    allocateMemoryRef(p);
    cout << "age: " << p->age <<endl;

}

//2. 常量引用
void test05(){

    //int &ret = 10; //引用了不合法的内存，不可以
    const int &ret = 10; //加入const后，编译器处理方式为：int temp = 10; const int &ret = temp;
    //既然编译器分配了内存，就可以通过指针进行修改
    int *p = (int*)&ret;
    *p = 20;
    cout << ret << " " << *p << endl;

}

////常量引用的使用场景：用来修饰形参
void showVal(const int &val){ //引用可以不产生新的变量，减少形参和实参传递的开销

    cout << "&val = " << hex << "0x" << &val << endl; 
}
void test06(){
    int a = 0;
    cout << "&a = " << hex << "0x" << &a << endl;
    showVal(a);
}

int main(int argc, char *argv[]){
    //test01();
    //test02();

    // int a = 10;
    // test03(a);
    // cout << a << endl;

    // int &ref = a;
    // ref = 300;
    // cout << ref << endl;

    // //等价于
    // int* const constP = &a;
    // *constP = 400;
    // cout << *constP << endl;

    //test04();

    //test05();
    test06();

    return 0;
}

