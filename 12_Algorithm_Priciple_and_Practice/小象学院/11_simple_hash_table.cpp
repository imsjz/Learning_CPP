#include <iostream>
#include <vector>
#include <array>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
};

int hash_function(int val, int hash_length){
    return val % hash_length;
}

void hash_insert(ListNode* hash_table[], ListNode* node, int table_len){
    int hash_key = hash_function(node->val, table_len);
    //插入
    node->next = hash_table[hash_key];
    hash_table[hash_key] = node;
}

bool hash_search(ListNode* hash_table[], int value, int table_len){
    int hash_key = hash_function(value, table_len);
    ListNode* head = hash_table[hash_key];
    while(head){
        if(head->val == value){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main(int argc, char* argv[]){
    //测试一下
    const int TABLE_LEN = 11;
    ListNode* hash_table[TABLE_LEN] = {0};
    vector<ListNode*> hash_node_vec;
    int test[8] = {1, 1, 4, 9, 20, 30, 150, 500};
    for(int i = 0; i < 8; ++i){
        hash_node_vec.push_back(new ListNode(test[i]));
    }
    //插入
    for(int i = 0; i < hash_node_vec.size(); ++i){
        hash_insert(hash_table, hash_node_vec[i], TABLE_LEN);
    }
    //遍历
    cout << "Hash table: " << endl;
    for(int i = 0; i < TABLE_LEN; ++i){
        cout << "[" << i << "]: ";
        ListNode* head = hash_table[i];
        while(head){
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
    }
    //搜索
    cout << "search " << endl;
    for(int i = 0; i < 10; ++i){
        if(hash_search(hash_table, i, TABLE_LEN)){
            cout << i << " is in the hash table" << endl;
        }
        else{
            cout << i << " is not..." << endl;
        }
    }
   
   return 0;
}
