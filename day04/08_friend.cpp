/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 10:43:52
 */
#include <iostream>

using namespace std;

class Building{
    
public:
    Building(){
        livingRoom = "客厅";
        bedRoom = "卧室";
    }

public:
    string livingRoom; //客厅
    friend void goodGay(Building *bd);
private:
    string bedRoom; //卧室
};

//全局函数 好基友
void goodGay(Building *bd){
    cout << "好基友正在访问" << bd->livingRoom << endl;
    cout << "好基友正在访问" << bd->bedRoom << endl;
}


void test01(){

    Building b1;
    goodGay(&b1);

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
