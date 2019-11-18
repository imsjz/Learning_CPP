#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREADS 5

void* PrintHello(void *threadid){
    //对传入的参数进行强制类型转换，由无类型指针变为整形指针，然后再读取
    int tid = *((int *)threadid);
    cout << "Hello Runoob! 线程ID, " << tid << endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int indexs[NUM_THREADS];
    int ret;
    for (int i = 0; i < NUM_THREADS; ++i){
        cout << "Main(): 创建线程，" << i << endl;
        indexs[i] = i;
        //传入的时候必须强制转换为void*,即无类型指针
        ret = pthread_create(&threads[i], NULL,
                PrintHello, (void*)&(indexs[i]));
        if(ret != 0){
            cout << "Error: 无法创建线程，" << ret << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
