/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-23 13:57:43
 */
/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class Person{
public:
    Person(string name, int score):name_(name), score_(score){}

    int score_;
    string name_;
};

void CreatePerson(vector<Person> &p){
    string name_seed = "ABCDE";
    for(int i = 0; i < 5; ++i){
        string name = "选手";
        name += name_seed[i];

        int score = 0;
        Person person(name, score);
        p.push_back(person);
    }
}

void set_score(vector<Person> &p){
    //分别对5个人评分
    for(vector<Person>::iterator it = p.begin(); it != p.end(); ++it){
        deque<int> d;
        for(int i = 0; i < 10; ++i){
            int score = rand() % 41 + 60; //60 ~ 100

            d.push_back(score);
        }

        //看看打分
        // for(deque<int>::iterator d_it = d.begin(); d_it != d.end(); ++d_it){
        //     cout << *d_it << " ";
        // }
        // cout << endl;
        //排序
        sort(d.begin(), d.end()); //从小到大
        //去除最高最低分
        d.pop_back(); //最高分
        d.pop_front(); //最低分

        //求平均
        int sum = 0;
        for(deque<int>::iterator d_it = d.begin(); d_it != d.end(); ++d_it){
            sum += (*d_it);
        }
        int average_score = sum / d.size();
        it->score_ = average_score;

    }
}

void get_score(const vector<Person> &v_p){
    for(vector<Person>::const_iterator c_it = v_p.cbegin(); c_it != v_p.cend(); ++c_it){
        cout << "姓名: " << c_it->name_ << " 分数: " << c_it->score_ << endl;
    }
}

void test01(){
    //设置随机种子
    srand((unsigned int)time(NULL));
    vector<Person> v_p;

    CreatePerson(v_p);
    for(vector<Person>::iterator it = v_p.begin(); it != v_p.end(); ++it){
        cout << "姓名: " << it->name_ << " 分数: " << it->score_ << endl;
    }
    cout << endl;

    //打分
    set_score(v_p);

    get_score(v_p);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
