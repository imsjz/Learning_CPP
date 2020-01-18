#include <iostream>
#include <vector>

using namespace std;
//二叉树的数据结构
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : 
        val(x), left(nullptr), right(nullptr){}
};

//二叉搜索树的插入
void BST_insert(TreeNode* node, TreeNode* insert_node){
    //暂不考虑insert_node为空的情况
    //当然也可以考虑
    if(!insert_node){
        return;
    }
    if(insert_node->val < node->val){
        if(node->left){
            BST_insert(node->left, insert_node);
        }
        else{
            node->left = insert_node;
        }
    }
    else{
        if(node->right){
            BST_insert(node->right, insert_node);
        }
        else{
            node->right = insert_node;
        }
    }
}

//二叉搜索树的查找
bool BST_search(TreeNode* node, int value){
    if(node->val == value){
        return true;
    }
    else if(value < node->val){
        if(node->left){
            return BST_search(node->left, value);
        }
        else{
            return false;
        }
    }
    else{
        if(node->right){
            return BST_search(node->right, value);
        }
        else{
            return false;
        }

    }
}

void preorder_print(TreeNode *node, int layer)
{
    if (!node)
    {
        return;
    }
    for (int i = 0; i < layer; ++i)
    {
        cout << "------";
    }
    cout << "[" << node->val << "]" << endl;
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

int main(int argc, char* argv[]){
   TreeNode root(8); //以8为根的二叉树
   vector<TreeNode*> node_vec;
   int test[] = {3, 10, 1, 6, 15};
   for(int i = 0; i < 5; ++i){
       node_vec.push_back(new TreeNode(test[i]));
   }

   //插入
   for(int i = 0; i < node_vec.size(); ++i){
       BST_insert(&root, node_vec[i]);
   }
   preorder_print(&root, 0);

   //测试bst_search
   for(int i = 0; i < 20; ++i){
       if(BST_search(&root, i)){
           cout << i << " found!" << endl;
       }
       else{
           cout << i << " not found!" << endl;
       }
   }
   for(int i = 0; i < node_vec.size(); ++i){
       delete node_vec[i];
   }

   return 0;
}
