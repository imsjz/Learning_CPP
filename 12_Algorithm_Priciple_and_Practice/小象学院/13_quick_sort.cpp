#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int arr[], int left, int right){
    if(left < right){
        int low = left;
        int high = right;
        int x = arr[low]; //x就是挖一个坑
        while(low < high){
            while(low < high && arr[high] >= x){
                --high;
            }
            if(low < high){
                arr[low] = arr[high];
                ++low;
            }
            while(low < high && arr[low] < x){
                ++low;
            }
            if(low < high){
                arr[high] = arr[low];
                --high;
            }
        }
        arr[low] = x;
        quick_sort(arr, left, low - 1);
        quick_sort(arr, low + 1, right);
        
    }
}

int main(int argc, char* argv[]){

    int array[] = {8, 3, 2, 4, 5, 9, 6, 8, 56};
    quick_sort(array, 0, 8);
    for(int ele : array){
        cout << ele << " ";
    }
    cout << endl;
    
    return 0;
}
