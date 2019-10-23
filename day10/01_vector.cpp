/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-21 14:26:38
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void test01(){
    //普通指针也算一种迭代器
    int arr[] = {1, 2, 3,4,3};

    int *p = arr;
    //or
    int *p2 = &arr[0];

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
        // cout << arr[i] << endl;
        // cout << *(p++) << endl;
        cout << *(p2++) << endl;
    }
}

void MyPrint(int v){
    cout << v << endl;
}

void test02(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    vector<int>::iterator it_begin = v.begin();
    vector<int>::iterator it_end = v.end();

    // //第一种遍历方法
    // while(it_begin != it_end){

    //     cout << *it_begin << endl;
    //     it_begin++;
    // }

    // //第二种遍历方法
    // for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
    //     cout << *it << endl;
    // }

    //第三种遍历方法
    for_each(v.begin(), v.end(), MyPrint);
}

//操作自定义数据类型
class Person{
public:
    Person(string name, int age):name_(name), age_(age){
    }
    string name_;
    int age_;
};

void test03(){
    vector<Person> v;
    Person p1("大头", 23);
    Person p2("张三", 32);
    Person p3("隔壁老王", 42);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //遍历
    for(vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
        cout << "姓名: " << (*it).name_ << " 年龄: " << it->age_ << endl;
    }
}

void test04(){
    vector<vector<int>> v_double;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for(int i = 0; i < 5; ++i){
        v1.push_back(i);
        v2.push_back(i+100);
        v3.push_back(i+1000);
    }
    v_double.push_back(v1);
    v_double.push_back(v2);
    v_double.push_back(v3);

    //遍历
    for(vector<vector<int>>::iterator it = v_double.begin(); it != v_double.end(); ++it){
        for(vector<int>::iterator vit = it->begin(); vit != it->end(); ++vit){
            cout << *vit << "\t";
        }
        cout << endl;
    }
}





int main(int argc, char *argv[]){
    // test01();
    // test02();
    // test03();
    test04();

    return 0;
}
