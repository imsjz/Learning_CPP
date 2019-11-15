/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-11 19:26:49
 */
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
    int row;
    int column;
    int *ptr;
public:
    Array2(){ ptr = NULL;}
    Array2(int paraRow, int paraColumn):row(paraRow), column(paraColumn){
        ptr = new int[row * column];
    }
    Array2(const Array2 &a);
    ~Array2();
    Array2& operator=(const Array2& a);
    int* operator[](int i);
    int& operator()(int i, int j);
};
Array2::~Array2(){
    if(ptr)
        delete [] ptr;
}
Array2& Array2::operator=(const Array2& a){
    if(ptr == a.ptr) return *this;
    if(ptr) delete [] ptr;
    row = a.row;
    column = a.column;
    ptr = new int[row * column];
    memcpy(ptr, a.ptr, sizeof(int)*row*column);
    return *this;
}

int* Array2::operator[](int i){
    return ptr + i * column;
}
int& Array2::operator()(int i, int j){
    return ptr[i*column + j];
}


int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}