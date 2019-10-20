/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 19:41:27
 */

#include <iostream>
//文件读写头文件
#include <fstream>
#include <cstring>

using namespace std;



//写文件
void test01(){
    //创建一个写对象 , 和文件绑定
    ofstream ofs("./test.txt", ios::out); //创建时直接绑定

    //也可后期指定
    ofstream ofs_2;
    ofs_2.open("./test.txt", ios::out);
    //判断打开是否成功
    if(!ofs.is_open()){
        cout << "打开文件失败" << endl;
    }
    ofs << "姓名:abc" << endl;
    ofs << "年龄:23" << endl;
    ofs << "性别:男" << endl;

    ofs.close();
}


//读文件
void test02(){
    //创建一个读对象
    ifstream ifs("./test.txt", ios::in);

    //判断是否打开成功
    if(!ifs.is_open()){
        cout << "打开失败" << endl;
    }

    // //第一种方式
    // char buf[1024];
    // while(ifs >> buf){ //按行读取 //>> 
    //     cout << buf << endl;
    // }

    // //第二种方式
    // char buf2[1024];
    // while(!ifs.eof()){ //eof 读到文件尾
    //     ifs.getline(buf2, sizeof(buf2));
    //     cout << buf2 << endl;
    // }

    //第三种 不推荐 按单个字符读取
    char c;
    while( (c = ifs.get()) != EOF){
        cout << c;
    }
    cout << endl;

}


int main(int argc, char *argv[]){
    // test01();
    test02();

    return 0;
}
