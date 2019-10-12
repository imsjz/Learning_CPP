/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-12 12:14:05
 */
#include <iostream>
#include <string>

using namespace std;

class Building;
class GoodGay{
public:
    GoodGay();
    void Visit();
    void VisitAsFriend();
private:
    Building *building_;
};

class Building{
public:
    Building();
    string living_room_; //客厅
    //让成员函数作为友元函数
    friend void GoodGay::VisitAsFriend();
private:
    string bed_room_; //卧室
};

GoodGay::GoodGay(){
    this->building_ = new Building;
}

void GoodGay::Visit(){
    cout << "好基友正在访问 " << this->building_->living_room_ << endl;
    //cout << "好基友正在访问 " << this->building_->bed_room_ << endl;
}

void GoodGay::VisitAsFriend(){
    cout << "好基友正在访问 " << this->building_->living_room_ << endl;
    cout << "好基友正在访问 " << this->building_->bed_room_ << endl;
}




Building::Building(){
    this->living_room_ = "客厅";
    this->bed_room_ = "卧室";
}

void test01(){

    GoodGay good_gay;
    good_gay.Visit();
    good_gay.VisitAsFriend();

}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
