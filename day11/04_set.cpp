/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-24 12:11:46
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Base
{
public:
};

void PrintSet(const set<int> &s)
{
    for (set<int>::const_iterator c_it = s.cbegin(); c_it != s.cend(); ++c_it)
    {
        cout << *c_it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s;

    s.insert(10);
    s.insert(2);
    s.insert(5);
    s.insert(8);

    PrintSet(s);
    //2 5 8 10
    s.erase(s.begin());
    PrintSet(s); // 5 8 10
    s.erase(8);  //5 10
    PrintSet(s);
}

/*
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end(); 

count(key);//查找键key的元素个数 

lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。 

upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。 

equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。 
*/

void test02()
{
    set<int> s;

    s.insert(10);
    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(8);

    //对于set 没有value, key就是value
    set<int>::iterator pos = s.find(3);
    if(pos != s.end()){
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    int count = s.count(8);
    cout << "count : " << count << endl;

    //2 5 8 10
    pair<set<int>::iterator, set<int>::iterator> pair_pos = s.equal_range(5); 
    cout << "lower_bound: " << *pair_pos.first << endl; //5
    cout << "upper_bound: " << *pair_pos.second << endl; //8
}

int main(int argc, char *argv[])
{
    // test01();
    test02();

    return 0;
}
