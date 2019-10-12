/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-11 16:08:59
 */
#include <iostream>

using namespace std;

//需求 单例模式 创建类中的对象,并且保证只有一个对象实例
class ChairMan{
public:
    // static ChairMan *singleMan; //静态变量，编译阶段就分配空间
    static ChairMan* getInstance(){
        return singleMan;
    }

private:
    ChairMan (){
        cout << "创建国家主席" << endl;
    }
    //拷贝构造函数
    ChairMan(const ChairMan &cm){}
    static ChairMan *singleMan; //静态变量，编译阶段就分配空间


};

ChairMan* ChairMan::singleMan = new ChairMan;

void test01(){

    // ChairMan cm1;
    // ChairMan cm2;
    // ChairMan *pcm3 = new ChairMan;

    // ChairMan *cm =  ChairMan::singleMan;
    // ChairMan *cm2 = ChairMan::singleMan;
    // ChairMan::singleMan = NULL;

    ChairMan *cm3 = ChairMan::getInstance();
    //ChairMan::getInstance() = NULL; //ERROR
    ChairMan *cm4 = ChairMan::getInstance();
    if(cm3 == cm4){
        cout << "cm3和cm4相同" << endl;
    }
    else{
        cout << "cm3和cm4不同" << endl;
    }

    // ChairMan *cm5 = new ChairMan(*cm3); //拷贝构造函数
    // if(cm3 == cm5){
    //     cout << "cm3和cm5相同" << endl;
    // }
    // else{
    //     cout << "cm3和cm5不同" << endl;
    // }
}
int main(int argc, char *argv[]){
    cout << "main函数" << endl;
    test01();

    return 0;
}
