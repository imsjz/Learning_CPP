#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* 
 * 字典树的学习和使用 *
*/

#define TRIE_MAX_CHAR_NUM 26

class TrieNode{
public:
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false){
        for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
            child[i] = nullptr;
        }
    }
};

void preorder_trie(TrieNode* node, int layer){
    for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if(node->child[i]){ //如果子节点不为空才进入
            for(int j = 0; j < layer; ++j){
                cout << "---";
            }
            cout << static_cast<char>(i+'a');
            if(node->child[i]->is_end){
                cout << "(end)";
            }
            cout << endl;
            preorder_trie(node->child[i], layer + 1);
        }
    }
}

void get_all_word_from_trie(TrieNode* node, string& word,
vector<string>& word_list){
    for(int i = 0; i < TRIE_MAX_CHAR_NUM; ++i){
        if(node->child[i]){
            word.push_back(i+'a');
            if(node->child[i]->is_end){
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.size() - 1, 1);
        }
    }
}

class TrieTree{
public:
    ~TrieTree(){
        for(int i = 0; i < _node_vec.size(); ++i){
            delete _node_vec[i];
        }
    }

    void insert(const char* word);
    TrieNode* root();
    bool searchWord(const char* word);
    bool isStartWith(const char* prefix);
    

private:
    TrieNode _root;
    vector<TrieNode*> _node_vec; //用这个更好回收内存   
    TrieNode* new_node(){
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
};

void TrieTree::insert(const char* word){
    TrieNode* ptr = &_root;
    while(*word){
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            ptr->child[pos] = new_node();
        }
        ptr = ptr->child[pos];
        ++word;
    }
    ptr->is_end = true;
}

TrieNode* TrieTree::root(){
    return &_root;
}

bool TrieTree::searchWord(const char* word){
    TrieNode* ptr = &_root;
    while(*word){
        int pos = *word - 'a';
        if(!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        ++word;
    }
    return ptr->is_end;
}
bool TrieTree::isStartWith(const char* prefix){
    TrieNode* ptr = &_root;
    while(*prefix){
        int pos = *prefix - 'a';
        if(!ptr->child[pos]){
            return false;
        }
        ptr = ptr->child[pos];
        ++prefix;
    }
    return true;
}

void test1(){
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;

    preorder_trie(&root, 0);

    vector<string> word_list;
    string word;
    get_all_word_from_trie(&root, word, word_list);
    for(string ele : word_list){
        cout << ele << endl;
    }
}

void test2(){
    TrieTree tree;
    tree.insert("abc");
    tree.insert("abcd");

    vector<string> word_list;
    string word;
    get_all_word_from_trie(tree.root(), word, word_list);
    for(string ele : word_list){
        cout << ele << endl;
    }

    cout << tree.searchWord("abc") << endl;
    cout << tree.searchWord("ab") << endl;

    cout << tree.isStartWith("ab") << endl;
    cout << tree.isStartWith("cd") << endl;
}



int main(int argc, char* argv[]){

    test2();






    
    return 0;
}
