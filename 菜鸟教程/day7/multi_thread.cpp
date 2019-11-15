#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void* say_hello(void* args){
    cout << "Hello Runoob!" << endl;
    return 0;
}

int main(){

    //定义线程的id变量
    pthread_t tids[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; ++i){
        //创建的线程id，线程参数，调用的函数，传入的函数参数
        //int pthread_create(pthread_t *tidp,const pthread_attr_t *attr, (void*)(*start_rtn)(void*),void *arg);
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0){
            cout << "pthread_create error: error_code = " << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来
    pthread_exit(NULL);
}
//编译用：g++ multi_threaad.cpp -lpthread -o multi_thread
