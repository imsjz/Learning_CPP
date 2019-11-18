#include <iostream>
using namespace std;
/*
  根据原先 C98 的标准，结构体定义的时候需要使用 typedef。
但是对于更新的 C99 标准和 C11 及以上的标准，typedef 可以省略或者强制省略。
对于定义 struct 的时候，C98需要添加struct，但是同时 C99 标准也去掉了。
*/


//eg: C98 standard:
typedef struct edge{
    int from;
    int to;
    int dis;
} edge_pointer;

int main(){
  //when create a new instance:
  //可以不用struct edge，直接用edge就可以了
  //struct edge Edge;
  edge Edge;
  Edge.from = 10;
  Edge.to = 20;
  Edge.dis = 33;
  cout << Edge.from << endl;
  cout << endl;


  edge_pointer test;
  test.from = 20;
  cout << test.from << endl;

  return 0;
}
