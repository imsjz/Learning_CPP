/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-25 12:51:49
 */
#include <iostream>
#include <cstring>
using namespace std;

int wlf[5]; //dragon, ninja, iceman, lion, wolf初始生命值
string wrname[5] = {"dragon", "ninja", "iceman", "lion", "wolf"}; //warrior的名字

//司令部类
class HeadQ{
    int lifen;//生命元
    int wno; //武士的最大编号
    int warriors[5]; //武士的数量
    string name; //司令部的名称
    bool stop; //是否停止制造武士
public:
    HeadQ(int lfn = 0, string snm = ""):lifen(lfn),wno(0),name(snm), stop(0){
        memset(warriors, 0, sizeof(warriors));
    }
    bool gen_wr(int time, int k); //生产武士，如果武士生命值大于司令生命元，返回false
    bool is_stop(int time); //判断是否停止制造武士，如果停止，输出相关信息
    bool get_stop(); //获取stop变量的值
};

bool HeadQ::gen_wr(int time, int k){
    if(lifen < wlf[k]){
        return false;
    }
    wno++;
    warriors[k]++;
    lifen -= wlf[k];
    cout.fill('0');
    cout.width(3);
    cout << time << " " << name << " " << wrname[k] << " " << wno << " born with strength "
        << wlf[k] << "," << warriors[k] << " " << wrname[k] << " in " << name << " headquater" << endl;

    return true;
}

bool HeadQ::is_stop(int time){
    bool flag = false; //标志是否可以继续制造武士
    for(int i = 0; i < 5; ++i){
        if(lifen > wlf[i]){
            flag = true;
            break;
        }
    }
    if(flag == false){
        cout.fill('0');
        cout.width(3);
        cout << time << " " << name << " headquater stops making warriors" << endl;
        stop = true;
        return true;
    }
    return false;
}

bool HeadQ::get_stop(){
    return stop;
}

int main(int argc, char *argv[]){
    int num;
    cin >> num;
    for(int i = 1; i <= num; ++i){
        int m; //生命元
        cin >> m;
        cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
        cout << "Case: " << i << endl;
        HeadQ redqt(m, "red");
        HeadQ blueqt(m, "blue");
        int redwrid[] = {2,3,4,1,0}; //红司令生产武士顺序：iceman、lion、wolf、ninja、dragon
        int bluewrid[] = {3,0,1,2,4}; //蓝司令生产武士顺序：lion、dragon、ninja、iceman、wolf

        int t = 0;
        int redk = 0;
        int bluek = 0;
        while(redqt.get_stop() == false || blueqt.get_stop() == false){ //只要有一个司令没停止，都可以继续
            while(redqt.get_stop() == false && redqt.is_stop(t) == false && redqt.gen_wr(t, redwrid[redk]) == false){
                redk = (redk + 1) % 5;
            }
            redk = (redk + 1) % 5;
            while(blueqt.get_stop() == false && blueqt.is_stop(t) == false && blueqt.gen_wr(t, bluewrid[bluek]) == false){
                bluek = (bluek + 1) % 5;
            }
            bluek = (bluek + 1) % 5;

            t++;
        }
    }
    return 0;
}