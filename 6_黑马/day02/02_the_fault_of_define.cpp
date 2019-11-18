/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-10 09:06:52
 */
#include <iostream>

using namespace std;

//宏的缺陷
#define MyAdd(x,y) ((x)+(y))

void test01(){

    int ret = MyAdd(10,20) * 20; //预期结果：600 然而：410
    cout << ret << endl;

}
inline void compare(int, int);
inline void compare(int a, int b){
    int ret = a < b ? a : b;
    cout << "ret = " << ret << endl;
}
int main(int argc, char *argv[]){
    //test01();
    compare(10, 20);

    return 0;
}
