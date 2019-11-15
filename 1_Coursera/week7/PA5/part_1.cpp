/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-15 16:33:26
 */
#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D{
public:
    //二维数组模板类
    template <class T1>
    class CArray2D{
        public:
            //一维数组模板类
            template <class T2>
            class CArray1D{
                public:
                    //构造函数，默认让a为NULL
                    CArray1D(){
                        a = NULL;
                    }
                    //summary: 分配空间给指针a
                    void set(int n){
                        if(a) delete [] a;
                        a = new T2[n];
                    }
                    //重载[]函数
                    T2& operator[](int i){
                        return a[i];
                    }
                    //析构函数
                    ~CArray1D(){
                        delete [] a;
                    }
                private:
                    //一维数组模板类声明一个T2指针a，用来存放T2类型的数组
                    T2 *a;
            };
            //CArray2D构造函数，默认为NULL
            CArray2D(){
                a1 = NULL;
            }
            //二维数组分配空间
            void set(int m, int n){
                a1 = new CArray1D<T1> [m];
                for (int i = 0; i < m; ++i){
                    a1[i].set(n);
                }
            }
            //析构函数
            ~CArray2D(){
                delete [] a1;
            }
            //运算符重载函数[]
            CArray1D<T1>& operator[](int m){
                return a1[m];
            }
        private:
            //定义一个CArray1D的模板类，类型为T1的指针
            CArray1D<T1> *a1;
    };
    CArray3D(int m, int n, int k){
        a2 = new CArray2D<T> [m];
        for(int i = 0; i < n; ++i){
            a2[i].set(n, k);
        }
    }
    ~CArray3D(){
        delete [] a2;
    }
    CArray2D<T>& operator[](int m){
        return a2[m];
    }
    private:
        //定义一个二维数组指针
        CArray2D<T> *a2;
};
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}