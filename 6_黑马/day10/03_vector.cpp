/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 09:49:24
 */
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Base{
public:

};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
        cout << v.capacity() << endl;
    }
    cout << typeid(v.begin()).name() << endl;
}


/*
vector<T> v; //采用模板实现类实现，默认构造函数 
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。 
vector(n, elem);//构造函数将n个elem拷贝给本身。 
vector(const vector &vec);//拷贝构造函数。 
*/

void PrintVector(vector<int> &v){
    // for(int i = 0; i < v.size(); ++i){
    //     cout << v[i] << "\t";
    // }
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test02(){
    vector<int> v;
    int arr[] = {1,2,3,4, 1,9};
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
    PrintVector(v1);

    vector<int> v2(10, 100);
    PrintVector(v2);

    //赋值使用
    // assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。 
    // assign(n, elem);//将n个elem拷贝赋值给本身。 
    // vector& operator=(const vector  &vec);//重载等号操作符 
    // swap(vec);// 将vec与本身的元素互换。 
    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    PrintVector(v3);

    v3.swap(v1);
    PrintVector(v3);

    if(v3.empty()){
        cout << "v3空" << endl;
    }
    else
    {
        cout << "v3 不为空" << endl;
    }

}

void test03(){
    vector<int> v;
    for(int i = 0; i < 100000; ++i){
        v.push_back(i);
    }
    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;

    v.resize(3);

    cout << "v的容量: " << v.capacity() << endl; //容量没有变小
    cout << "v的大小: " << v.size() << endl;

    //巧用swap
    vector<int>(v).swap(v);

    cout << "v的容量: " << v.capacity() << endl; //容量没有变小
    cout << "v的大小: " << v.size() << endl;
}

//reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。 
void test04(){
    vector<int> v;
    v.reserve(100000);

    int *p = NULL;
    int num = 0;
    for(int i = 0; i < 100000; ++i){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            ++num;
        }
    }
    cout << num << endl;
}

void test05(){
    vector<int> v;
    v.push_back(1);
    v.assign(10, 23);
    v.push_back(1);
    PrintVector(v);

    v.insert(v.begin(), 100);
    PrintVector(v);
    v.insert(v.begin(), 10, 22);
    PrintVector(v);

}

void test06(){
    //逆序排序
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    //
    for(vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit){
        cout << *rit << endl;
    }

    //vector迭代器是随机访问的迭代器, 支持跳跃式访问
    vector<int>::iterator it_begin = v.begin();
    it_begin = it_begin + 3;
    //

    list<int> lst;
    for(int i = 0; i < 10; ++i){
        lst.push_back(i);
    }
    list<int>::iterator it_list = lst.begin();
    // it_list = it_list + 1;
    ++it_list;
}






int main(int argc, char *argv[]){

    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();

    return 0;
}
