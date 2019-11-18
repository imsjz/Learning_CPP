/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-30 12:08:53
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

class Base{
public:

};
void test01(){
    /*
	merge算法 容器元素合并，并存储到另一容器中
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
    merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
*/
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; ++i){
        v1.push_back(i);
        v2.push_back(i+1);
    }

    vector<int> target;
    target.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), target.end(), [](int val){cout << val << endl;});

}

void test02(){
/*
	sort算法 容器元素排序
	注意:两个容器必须是有序的
	@param beg 容器1开始迭代器
	@param end 容器1结束迭代器
	@param _callback 回调函数或者谓词(返回bool类型的函数对象)
    sort(iterator beg, iterator end, _callback)
*/
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(90);
    v1.push_back(50);

    sort(v1.begin(), v1.end()); //升序
    for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";});

    cout << endl;
    //降序
    sort(v1.begin(), v1.end(), greater<int>());
    for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";});



}


int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
