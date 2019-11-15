/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-21 12:11:49
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

class CStudent{
    public:
        struct CInfo{
            int id;
            string name;
        };
        int scores;
        CInfo info;
};
typedef multimap<int, CStudent::CInfo> MAP_STD;
int main(){
    MAP_STD mp; //一个模板类对象，用来存放学生信息
    CStudent st; //学生类对象
    string cmd;
    while(cin >> cmd){
        if(cmd == "Add"){
            cin >> st.info.name >> st.info.id >> st.scores;
            //将学生信息加入到multimap中
            mp.insert(MAP_STD::value_type(st.scores, st.info));
        }
        else if(cmd == "Query"){
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);
            if(p != mp.begin()){
                --p;
                score = p->first;
                MAP_STD::iterator maxp = p;
                int maxId = p->second.id;
                for(; p != mp.begin() && p->first == score; --p){
                    if (p->second.id > maxId){
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                if(p->first == score)
                    if(p->second.id > maxId){
                        maxp = p;
                        maxId = p->second.id;
                    }

                cout << maxp->second.name << " " << maxId << " " << maxp->first << endl;
            }
            else
                cout << "Nobody" << endl;
        }
    }

    return 0;
}