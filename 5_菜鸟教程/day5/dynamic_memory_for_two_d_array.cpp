#include <iostream>
using namespace std;

int main(){
    int **p;
    int i,j;
    //分配4行8列的二维数据
    p = new int *[4];
    for (i = 0; i < 4; i++){
        p[i] = new int[8];
    }

    for (i = 0; i < 4; i++){
        for (j = 0; j < 8; j++){
            p[i][j] = i * j;
        }
    }
    //print data
    for (i = 0; i < 4; i++){
        for (j = 0; j < 8; j++){
            if(j==0) cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    //开始释放内存
    for(i = 0; i < 4; i++){
        delete [] p[i];
    }
    delete [] p;
    return 0;
}
