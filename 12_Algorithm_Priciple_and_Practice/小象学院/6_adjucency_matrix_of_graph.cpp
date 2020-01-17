#include <iostream>
#include <array>
using namespace std;

int main(){
    //构造是的有向图
    const int MAX_N = 5;
    array<array<int, 5>, 5> graph = {0}; //使用邻接矩阵，适用于稠密图，如果用于稀疏图造成空间浪费
    graph[0][2] = 1;
    graph[0][4] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;
    cout << "Graph: " << endl;
    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < 5; ++j){
            cout << " " << graph[i][j] ;
        }
        cout << endl;
    }

    return 0;
}