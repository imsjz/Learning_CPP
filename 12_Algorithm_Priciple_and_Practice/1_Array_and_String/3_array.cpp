/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-15 11:39:28
 */
#include <iostream>
#include <string>
using namespace std;

//############################################//
//################   例子1   ####################//
//############################################//
// Remove Element
// Given an array and a value, remove all occurrences of that value in
// place and return the new length.
// The order of elements can be changed, and the elements after the new
// length don't matter.
// Example
// Given an array [0,4,4,0,0,2,4,4], value=4
// return 4 and front four elements of the array is [0,0,0,2]
//移除元素
//两种做法： 1. 通过容器遍历， 遇到相同的值则删掉，注意erase返回的是下一个迭代器, 因此要注意回来
//         2. 通过数组，如果遇到相同值，把最后的元素放进此位置，这个同样也要注意把指针回溯，因为你不知道换进来的这个元素时候是等于待移除值
#include <vector>
#include <cstring>
namespace example1
{
    class Solution{
    public:
        int RemoveElement(vector<int>& v, int elem){
            for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
                if(*it == elem){
                    it = v.erase(it); //返回的是下一个迭代器
                    --it; //因此要--返回上一个
                }
            }
            return v.size();
        }

        int RemoveElement2(int arr[], int n, int value){
            for(int i = 0; i < n; ++i){
                if(arr[i] == value){
                    arr[i] = arr[n - 1];
                    --i;
                    --n;
                }
            }
            return n;
        }
    };
    
    
} // namespace example1

namespace example2
{
    // Remove Duplicates from Sorted Array I
    // Given a sorted array, remove the duplicates in place such that each
    // element appear only once and return the new length.
    // Do not allocate extra space for another array, you must do this in place
    // with constant memory.
    // 空间复杂度O(1)
    // For example,
    // Given input array nums = [1,1,2],
    // Your function should return length = 2, with the first two elements of
    // nums being 1 and 2 respectively. It doesn't matter what you leave
    // beyond the new length.
    // 限制：需要空间复杂度为1，也即不能创建数组来存储，只能就地置换
    // 采用的策略，用size=0开始来标注新的数组位置， 通过遍历i来判断是否相等，用不等来进入条件，而不是用相等来进入条件
    class Solution{
    public:
        int removeDuplicates(vector<int>& v){
            if(v.empty()){
                return 0;
            }
            int size = 0;
            for(vector<int>::size_type i = 0; i < v.size(); ++i){
                if(v[size] != v[i]){
                    v[++size] = v[i];
                }
            }
            return ++size;
        }
    };
    

} // namespace example2



int main(int argc, char const *argv[])
{
    // vector<int> vec{0,4,4,0,0,2,4,4};
    // example1::Solution* sln = new example1::Solution;
    // int len = sln->RemoveElement(vec, 4);
    // cout << len << endl;
    // for(auto e: vec){
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout << "--------------------------" << endl;
    // int arr[] = {0,4,4,0,0,2,4,4};
    // int arr_remove_len = sln->RemoveElement2(arr, sizeof(arr) / sizeof(arr[0]), 4);
    // cout << arr_remove_len << endl;
    // for(int i = 0; i < arr_remove_len; ++i){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;
    vector<int> num{1,1,2};
    example2::Solution* sln = new example2::Solution;
    int len = sln->removeDuplicates(num);
    for(int i = 0; i < len; ++i){
        cout << num.at(i) << " ";
    }
    cout << endl;
    return 0;
}
