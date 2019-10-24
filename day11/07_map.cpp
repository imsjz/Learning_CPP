/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-24 17:29:59
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Base
{
public:
};

/*
map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数

3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.8.2.4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
*/
void test01()
{
    map<int, int> m; //key 和value都是int型
    //插入值
    //4种方式
    //1.
    m.insert(pair<int, int>(1, 10));

    //2.推荐使用
    m.insert(make_pair(2, 20));

    //3.
    m.insert(map<int, int>::value_type(3, 30)); //不推荐
    //4.不推荐
    m[4] = 40;

    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    //不推荐4的原因
    cout << m[5] << endl; //不存在的话会自动增加, 不好
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
