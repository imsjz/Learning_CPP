/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-30 15:57:31
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

class Base{
public:

};
void test01(){
/*
	copy算法 将容器内指定范围的元素拷贝到另一容器中
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param dest 目标起始迭代器
    copy(iterator beg, iterator end, iterator dest)
*/
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    vector<int> v_target;
    v_target.resize(v.size());
    copy(v.begin(), v.end(), v_target.begin());

    for_each(v_target.begin(), v_target.end(), [](int val){cout << val << " ";});
    cout << endl;
    copy(v_target.begin(), v_target.end(), ostream_iterator<int>(cout , " "));

}

class MyComare{
public:
    bool operator()(int val){
        return val > 3;
    }
};


void test02(){
/*
	replace算法 将容器内指定范围的旧元素修改为新元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param oldvalue 旧元素
	@param oldvalue 新元素
    replace(iterator beg, iterator end, oldvalue, newvalue)
*/
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }

    //把容器中的3 替换成300
    replace(v.begin(), v.end(), 3, 300);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    //把容器中大于3的替换成30000
    replace_if(v.begin(), v.end(), MyComare(), 30000);
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

}

void test03(){
/*
	swap算法 互换两个容器的元素
	@param c1容器1
	@param c2容器2
    swap(container c1, container c2)
*/
    vector<int> v1;
    for(int i = 0; i < 10; ++i){
        v1.push_back(i);
    }

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(30);
    v2.push_back(20);
    v2.push_back(40);

    cout << "交换前的数据: " << endl;

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "交换后的数据: " << endl;

    swap(v1, v2); //不用分配空间, 感觉是换了v1和v2的指向
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}



int main(int argc, char *argv[]){
    // test01();
    // test02();
    test03();

    return 0;
}
