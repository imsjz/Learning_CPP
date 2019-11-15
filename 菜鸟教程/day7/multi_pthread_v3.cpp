#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;


#define NUM_THREADS 5

struct thread_data{
    int thread_id;
    char *message;
};

void* PrintHello(void *threadarg){
    thread_data *my_data;
    my_data = (thread_data *)threadarg;
    cout << "Thread id: " << my_data->thread_id << endl;
    cout << "Thread message: " << my_data->message << endl;

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    thread_data td[NUM_THREADS];
    int ret;
    for (int i = 0; i < NUM_THREADS; ++i){
        cout << "Main(): 创建线程，" << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)"This is message";
        //传入的时候必须强制转换为void*,即无类型指针
        ret = pthread_create(&threads[i], NULL,
                PrintHello, (void*)&(td[i]));
        if(ret != 0){
            cout << "Error: 无法创建线程，" << ret << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
