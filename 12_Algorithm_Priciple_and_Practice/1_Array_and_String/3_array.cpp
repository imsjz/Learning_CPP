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

// 两个排好序的数组，A和B， 需要把这两个都放进A里，假设A有足够的空间，按照大小序列
// A 和 B都是从小到大排序
namespace example3
{
    class Solution{
    public:
        void MergeSortedArray(int A[], int m, int B[], int n){
            int len = m + n;
            //从后往前填充,如果从前往后的话A的值会被覆盖掉
            while(m > 0 && n > 0){
                if(A[m-1] > B[n-1]){
                    A[--len] = A[--m];
                }else{
                    A[--len] = B[--n];
                }
            }
            //当其中一个变为0了之后
            while(m > 0){
                A[--len] = A[--m];
            }
            while(n > 0){
                A[--len] = B[--n];
            }
        }
    };
    
} // namespace example3

namespace example4
{
    // Partition
    // Given an array nums of integers and an int k, partition the array
    // (i.e move the elements in "nums") such that:
    // All elements < k are moved to the left
    // All elements >= k are moved to the right
    // Return the partitioning index, i.e the first index i nums[i] >= k.
    // Example
    // If nums=[3,2,2,1] and k=2, a valid answer is 1.
    // If all elements in nums are smaller than k, then return nums.length
    // Challenge
    // Can you partition the array in-place and in O(n)?
    class Solution{
    public:
        //第一种解法: 用一个right来标记,用i来跑数组判断
        //空间复杂度1,时间复杂度n
        int partitionArray1(vector<int>& nums, int k){
            int right = 0; //一开始默认这个区分下标为0
            for(int i = 0; i < nums.size(); ++ i){
                //这个判断条件很重要
                if(nums.at(i) < k && i > right){
                    //如果i所在的值小于k,那么就要置换,同时right自增1
                    int temp = nums.at(i);
                    nums.at(i) = nums.at(right);
                    nums.at(right) = temp;
                    ++right;
                }
            }
            return right;
        }
        //第二种解法: 用快速排序的方法做,但是不需要用到递归
        int partitionArray2(vector<int>& nums, int k){
            int i = 0, j = nums.size() - 1;
            while(i <= j){

                while(i <= j && nums[i] < k) ++i;
                while(i <= j && nums[j] >= k) --j;
                if(i <= j){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;//交换
                    ++i;
                    --j;
                }
            }
            return i;
        }
    };
    
} // namespace example4

namespace example5
{
    class Solution{
    public:
        int findMedian(vector<int>& nums){
            if(nums.empty()) return 0;
            int len = nums.size();
            return helper(nums, 0, len - 1, (len + 1)/ 2); //最后一个参数+1是为了处理奇数和偶数情况,+1可以让两者除于2的情况相同
        }

    
        //nums: 数组
        //l: 数组左下标, r右下标, size 数组大小
        int helper(vector<int>& nums, int l, int r, int size){
            int pivot = findPivot(nums, l, r); //the index of pivot

            if((pivot - l + 1) == size){
                return nums[pivot];
            }
            else if((pivot - l + 1) > size){
                return helper(nums, l, pivot - 1, size);
            }
            else{
                return helper(nums, pivot + 1, r, size - (pivot - l + 1));
            }
            
        }
        int findPivot(vector<int>& nums, int l, int r){
            if(nums.empty()) return 0;
            int temp = nums.at(l); //用temp保存坑的值
            while(l < r){ //不能包含=
                while(l < r && nums.at(r) > temp) --r;
                if(l < r){
                    nums.at(l) = nums.at(r);
                    ++l;
                }
                while(l < r && nums.at(l) <= temp) ++l;
                if(l < r){
                    nums.at(r) = nums.at(l);
                    --r;
                }
            }
            nums.at(l) = temp;
            return l;
        }
    };
    
} // namespace example5


template <typename T>
void print_array(T t){
    typedef typename T::iterator iter;
    for(iter it = t.begin(); it != t.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

//数组的
template <typename T>
void print_array(T t, int size){
    for(int i = 0; i < size; ++i){
        cout << t[i] << " ";
    }
    cout << endl;
}


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
    // vector<int> num{1,1,2};
    // example2::Solution* sln = new example2::Solution;
    // int len = sln->removeDuplicates(num);
    // for(int i = 0; i < len; ++i){
    //     cout << num.at(i) << " ";
    // }
    // cout << endl;
    // int A[9] = {1,3,5,7};
    // int B[5] = {0,2,4,6,8};
    // example3::Solution sln;
    // sln.MergeSortedArray(A, 4, B, 5);
    // for(auto e: A){
    //     cout << e << " ";
    // }
    // cout << endl;
    // vector<int> num = {3,2,2,1,4,5,63,3,2};
    // print_array(num);
    // // int nums[] = {1,2,3,3};
    // // print_array(nums, 4);
    // example4::Solution sln;
    // int index = sln.partitionArray2(num, 3);
    // cout << index << endl;
    // print_array(num);
    vector<int> nums = {4,5,1,2,3};
    example5::Solution sln;
    // sln.findPivot(nums, 0, 4);
    // print_array(nums);
    cout << sln.findMedian(nums) << endl;
    return 0;
}
