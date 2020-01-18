#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void BFS_print(TreeNode* root){
    queue<TreeNode*> tree_que;
    tree_que.push(root);
    while(!tree_que.empty()){
        TreeNode* node = tree_que.front();
        cout << '[' << node->val << ']' << endl;
        tree_que.pop();
        if(node->left){
            tree_que.push(node->left);
        }
        if(node->right){
            tree_que.push(node->right);
        }
    }
}

int main(){

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    BFS_print(&a);

    return 0;
}