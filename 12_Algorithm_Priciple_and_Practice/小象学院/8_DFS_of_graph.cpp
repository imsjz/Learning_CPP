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

//因为图可能有环，因此相较于树来说，需要一个visit数组来标记这个节点是否被访问
void DFS_graph(GraphNode* node, int* visit){
    visit[node->label] = 1;
    cout << node->label << " ";
    for(int i = 0; i < node->neighbors.size(); ++i){
        if(visit[node->neighbors[i]->label] == 0){
            DFS_graph(node->neighbors[i], visit);
        }
    }
}

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

    //深度优先搜索
    int visit[MAX_N] = {0};
    for(int i = 0; i < MAX_N; ++i){
        if(visit[i] == 0){ //没被访问的才访问
            cout << "from label(" << graph[i]->label << "): ";
            DFS_graph(graph[i], visit);
            cout << endl;
        }
    }

    //最后要回收内存
    for(int i = 0; i < MAX_N; ++i){
        delete graph[i];
    }

    return 0;
}