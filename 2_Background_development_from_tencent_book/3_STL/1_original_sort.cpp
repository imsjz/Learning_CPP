/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-07-30 12:43:03
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
#define max_size 10

/*
比较两个数的大小：
返回的值>0，则a>b
...
*/
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    int arr[max_size];
    int n = 0;
    while(cin >> arr[n++]){
        if(arr[n-1] == 0)
            break;
    };
    qsort(arr, n, sizeof(int), cmp);
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}