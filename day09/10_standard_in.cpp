/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-20 14:31:15
 */
#include <iostream>

using namespace std;


// 标准输入流对象cin，重点掌握的函数 

// cin.get() //一次只能读取一个字符 

// cin.get(一个参数) //读一个字符 

// cin.get(两个参数) //可以读字符串 , 不吃换行符

// cin.getline() 

// cin.ignore() 

// cin.peek() 

// cin.putback() 

void test01(){
    char c = cin.get();
    cout << "c = " << c << endl;

    c = cin.get();
    cout << "c = " << c << endl;

    c = cin.get();
    cout << "c = " << c << endl;
}

void test02(){
    char buf[1024];
    cin.get(buf, 1024); //不读取换行符, 让它继续留在缓冲区

    char c = cin.get();
    if(c == '\n'){
        cout << "换行还在缓冲区" << endl;
    }
    else{
        cout << "换行不在" << endl;
    }

    cout << buf << endl;
}

void test03(){
    char buf[1024];
    cin.getline(buf, 1024); //读取换行符, 但是扔掉了

    char c = cin.get();
    if(c == '\n'){
        cout << "换行还在缓冲区" << endl;
    }
    else{
        cout << "换行不在" << endl;
    }

    cout << buf << endl;
}



void test04(){

    // cin.ignore(); //没有参数代表忽略一个字符
    cin.ignore(2); //忽略两个

    char c = cin.get();

    cout << "c = " << c << endl;
}

void test05(){

    //peek 偷看一眼, 然后再放回缓冲区
    char c = cin.peek();

    cout << "c = " << c << endl;

    c = cin.get();

    cout << "c = " << c << endl;
}

void test06(){
    char c = cin.get();

    cin.putback(c);

    char buf[1024];

    cin.getline(buf, 1024);

    cout << buf << endl;
}

//案例1 : 判断用户输入的是字符串还是数字(不考虑1lkjl混合数据)
void test07(){
    cout << "请输入一串数字或者字符串" << endl;

    char c = cin.peek();
    if(c >= '0' && c <= '9'){
        int num;
        cin >> num;
        cout << "您输入的是数字, 数字为" << num << endl;
    }
    else{
        char buf[1024];
        cin >> buf;
        cout << "您输入的是字符串, 字符串为" << buf << endl;
    }
}


void test08(){
    cout << "请输入1到10之间的数字: " << endl;
    // int num;
    char c;
    while(c = getchar(),!isdigit(c)); //直至第一个为数字
    int r = c - '0';
    while(c = getchar(),isdigit(c)){ //后续为数字
        r = r * 10 + c - '0';
    }
    cout << r << endl;
}


//案例2: 输入1-10的数字, 正确打印,错误重新输入 
void test09(){
    int num;
    cout << "请输入1到10之间的数字: " << endl;
    while(true){
        cin >> num;
        if(num >= 1 && num <= 10){
            cout << num << endl;
            break;
        }
        else{
            cout << "请重新输入" << endl;
            cin.clear();
            cin.ignore(); //用这个好点
            continue;
        }

    }
}

int main(int argc, char *argv[]){
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    // test08();
    test09();

    return 0;
}
