/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-25 09:05:20
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Base{
public:
    bool operator()(int val){
        return val > 20;
    }

};

//一元谓词
void test01(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(43);
    v.push_back(23);

    //查找第一个大于20的数字
    vector<int>::iterator it =find_if(v.begin(), v.end(), Base());
    cout << *it << endl;
}

//二元谓词

class MyCompare{
public:
    bool operator()(int val1, int val2){
        return val1 > val2;
    }
};


void PrintVector(const vector<int> &v)
{
    for (vector<int>::const_iterator c_it = v.cbegin(); c_it != v.cend(); ++c_it)
    {
        cout << *c_it << " ";
    }
    cout << endl;
}

void test02(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(43);
    v.push_back(23);


    MyCompare my_compare;

    sort(v.begin(), v.end(), my_compare);

    // PrintVector(v);
    //匿名函数 lambda表达式  [](){}
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    cout << endl;
}

int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
