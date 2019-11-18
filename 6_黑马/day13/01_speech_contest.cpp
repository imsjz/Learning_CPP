/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-11-01 10:51:32
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <numeric>
#include <functional>

using namespace std;

/*

需求分析：
		1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号

		2) 第1轮	选手抽签 选手比赛 查看比赛结果 
		3) 第2轮	选手抽签 选手比赛 查看比赛结果
		4) 第3轮	选手抽签 选手比赛 查看比赛结果

*/
class Speaker
{
public:
    string name_;  //姓名
    int score_[3]; //得分数组
};

void CreateSpeaker(vector<int> &v, map<int, Speaker> &m)
{
    string name_seed = "ABCDEFGHIJKLMNOPQRSTUVWX";
    Speaker temp_speaker;
    for (int i = 0; i < name_seed.size(); ++i)
    {
        string name = "选手";
        name += name_seed[i];
        // cout << i << endl;
        // cout << name << endl;
        // cout << name_seed.size() << endl;

        temp_speaker.name_ = name;
        for (int j = 0; j < 3; ++j)
        {
            temp_speaker.score_[j] = 0; //把数组初始化
        }
        //对象创建完毕, 用容器装起来
        v.push_back(i + 100); //编号: 100~123
        m.insert(make_pair(i + 100, temp_speaker));
    }
}

void SpeechDraw(vector<int> &v)
{
    //洗牌
    random_shuffle(v.begin(), v.end());
}

/**
 * @description: 选手比赛函数
 * @param index: 比赛场次
 * @param v1: 比赛选手编号
 * @param m: 选手编号和具体选手
 * @param v2: 晋级选手编号
 * @return: void
 */
void SpeechContest(int index, vector<int> &v1, map<int, Speaker> &m, vector<int> &v2)
{

    multimap<int, int, greater<int>> group_map; //key 分数  value 编号 //分数从高到低
    int num = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    {
        ++num;
        deque<int> d_score;
        for (int i = 0; i < 10; ++i)
        {
            int score = rand() % 41 + 60;
            d_score.push_back(score);
        }
        sort(d_score.begin(), d_score.end());
        d_score.pop_back();
        d_score.pop_front();
        int average_score = accumulate(d_score.begin(), d_score.end(), 0) / d_score.size();

        //将平均分放入m容器中
        m[*it].score_[index] = average_score;

        //每6个人 取前三名 晋级
        //临时容器 保存6个人
        //临时容器 插入数据
        group_map.insert(make_pair(average_score, *it));
        if (num % 6 == 0)
        {

            // cout << "小组比赛成绩: " << endl;
            // for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(); ++mit)
            // {
            //     cout << "编号: " << mit->second << " 姓名: " << m[mit->second].name_ << " 分数: " << m[mit->second].score_[index] << endl;
            // }
            //取前三名
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(), count < 3; ++mit, ++count)
            {
                v2.push_back(mit->second);
            }
            group_map.clear();
        }
    }
}


void showScore(int index, const vector<int> &v, const map<int, Speaker> &m){
    cout << "第 " << index + 1 << " 轮 比赛成绩如下: " << endl;
    for(map<int, Speaker>::const_iterator mit = m.cbegin(); mit != m.cend(); ++mit){
        cout << "选手编号: " << mit->first << " 姓名: " << mit->second.name_ << " 分数: " << mit->second.score_[index] << endl;
    }
    cout << "晋级的选手: " << endl;
    for(vector<int>::const_iterator cit = v.cbegin(); cit != v.cend(); ++cit){
        cout << "选手编号: " << *cit << " 姓名: " << m.at(*cit).name_ << " 分数: " << m.at(*cit).score_[index] << endl;
    }
}

void test01()
{
    vector<int> v1;      //存放选手编号
    map<int, Speaker> m; //存放选手编号和对应的具体选手

    //创建选手
    CreateSpeaker(v1, m);

    //测试创建是否成功
    // for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); ++it)
    // {
    //     cout << "编号: " << it->first << " 姓名: " << it->second.name_ << endl;
    // }
    //

    //抽签
    SpeechDraw(v1);

    vector<int> v2; //进入下一轮比赛的人员编号
    //比赛
    SpeechContest(0, v1, m, v2);

    //显示比赛结果
    showScore(0, v2, m);

    //第二轮比赛
    SpeechDraw(v2);

    vector<int> v3;
    //比赛
    SpeechContest(1, v2, m, v3);
    showScore(1, v3, m);

    //第三轮比赛
    SpeechDraw(v3);
    vector<int> v4;
    SpeechContest(2, v3, m, v4);
    showScore(2, v4, m);
}
int main(int argc, char *argv[])
{
    test01();

    return 0;
}
