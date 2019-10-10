/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-09 10:37:28
 */
#include <iostream>

using namespace std;
namespace a{
    int sunwukong = 30;
}

void test(){

    int sunwukong = 20;
    
    //1. using 声明
    //using a::sunwukong; //用using之后说明以下代码用a命名空间下的sunwukong, 但是又有就近原则, 因此产生二义性

    cout << sunwukong << endl;
}

//using 编译指令
namespace b {
    int sunwukong = 40;
}

void test02(){
    //int sunwukong = 89;

    //using 编译指令
    // using namespace a;//打开房间,但是还没指明命令
    // cout << sunwukong << endl; //89,也就是打印了就近原则
    using namespace a;
    using namespace b;
    //如果打开多个房间,要避免二义性
    cout << a::sunwukong << endl;
}

int main(int argc, char *argv[]){
    
    // test();
    test02();
    return 0;
}
