/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2020-01-09 21:16:44
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void preorder_print(TreeNode *node, int layer)
{
    if (!node)
    {
        return;
    }
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
    for (int i = 0; i < layer; ++i)
    {
        cout << "------";
    }
    cout << "[" << node->val << "]" << endl;
    // preorder_print(node->left, layer + 1);
    // preorder_print(node->right, layer + 1);
}
int main(int argc, char *argv[])
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    TreeNode g(7);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    preorder_print(&a, 0);

    return 0;
}
