/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 21:09:29
 */
#include <iostream>
#include <cstring>

using namespace std;

class Person{
public:
    Person(const char *name, int age){
        m_Name = (char *)malloc(strlen(name) + 1);
        strcpy(m_Name, name);
        m_age = age;
    }
    // 拷贝构造，系统会提供默认拷贝构造函数
    // 自己提供拷贝构造, 因为浅拷贝会导致堆内存重复释放
    Person(const Person &p){
        m_age = p.m_age;
        m_Name = (char *)malloc(sizeof(p.m_age));
        strcpy(m_Name, p.m_Name);
    }

    ~Person(){
        cout << "析构函数调用" << endl;
        if(m_Name != NULL){
            free(m_Name);
            m_Name = NULL;
            cout << "cool" << endl;
        }
        
    }
    //姓名
    char *m_Name;
    int m_age;
};

void test01(){

    const char *name = "孙悟空";
    Person p1(name, 23);
    cout << &p1.m_Name << endl;
    //拷贝构造
    Person p2(p1);
    cout << &p2.m_Name << endl;

}

class A{
public:
    A(int _size):size(_size){
        data = new int[size];
    }
    //深拷贝
    //在复制构造函数里新建内存
    A(const A &a){
        size = a.size;
        data = new int[size];
        data = a.data;
    }

    ~A(){
        delete [] data;
        cout << "delete " << endl;
    }

    int *data;
    int size;
};

void test02(){

    A a(2);
    
    A b = a;
    cout << &a.data[0] << endl;

    cout << &b.data[0] << endl;
}

void test03(){

    int *arr = (int*)malloc(sizeof(int));
    free(arr);
    free(arr);//两个竟然不会报错...
}

int main(int argc, char *argv[]){
    //test01();
    test02();
    test03();

    return 0;
}
