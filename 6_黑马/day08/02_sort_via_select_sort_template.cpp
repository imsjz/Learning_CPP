/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-18 13:24:16
 */
#include <iostream>

using namespace std;

//对char和int数组进行排序, 排序规则, 从大到小, 利用选择排序

template<class T>
void MySwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void MySort(T arr[], int len){
    for(int i = 0; i < len; ++i){
        int max = i;
        for(int j = i + 1; j < len; ++j){
            if(arr[max] < arr[j])
                max = j;
        }
        if(max != i){
            //交换数据
            MySwap<T>(arr[i], arr[max]);
        }
    }
}

//输出数组元素的模板
template<class T>
void PrintArray(T arr[], int len){
    for(int i = 0; i < len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01(){
    char char_arr[] = "helloworld";
    int num_arr = sizeof(char_arr) / sizeof(char_arr[0]);
    MySort<char>(char_arr, num_arr);
    PrintArray<char>(char_arr, num_arr);

    int int_arr[] = {1,23,4,2,4,5,6,3,5,5};
    int length_int_arr = sizeof(int_arr) / sizeof(int_arr[0]);
    MySort<int>(int_arr, length_int_arr);
    PrintArray<int>(int_arr, length_int_arr);
}
int main(int argc, char *argv[]){
    test01();

    return 0;
}
