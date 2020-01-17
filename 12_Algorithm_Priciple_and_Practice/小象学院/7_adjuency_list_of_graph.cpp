#include <iostream>
#include <vector>

using namespace std;

//需要定义图的数据结构
class GraphNode{
public:
    int label; //图的顶点值
    vector<GraphNode*> neighbors;
    GraphNode(int x):label(x){}
};

int main(){
    //构造是的有向图
    const int MAX_N = 5;
    //5个图顶点
    GraphNode* graph[MAX_N];
    //给每个指针申请内存
    for(int i = 0; i < MAX_N; ++i){
        graph[i] = new GraphNode(i);
    }
    //添加边
    graph[0]->neighbors.push_back(graph[2]);
    graph[0]->neighbors.push_back(graph[4]);
    graph[1]->neighbors.push_back(graph[0]);
    graph[1]->neighbors.push_back(graph[2]);
    graph[2]->neighbors.push_back(graph[3]);
    graph[3]->neighbors.push_back(graph[4]);
    graph[4]->neighbors.push_back(graph[3]);

    cout << "graph: " << endl;
    for(int i = 0; i < MAX_N; ++i){
        cout << "label(" << i << "): ";
        for(int j = 0; j < graph[i]->neighbors.size(); ++j){
            cout << graph[i]->neighbors[j]->label << " ";
        }
        cout << endl;
    }
    //最后要回收内存
    for(int i = 0; i < MAX_N; ++i){
        delete graph[i];
    }

    return 0;
}