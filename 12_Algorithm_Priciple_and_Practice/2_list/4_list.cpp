/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-15 21:27:41
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class ListNode
{
public:
    ListNode(int v) : val(v), next(nullptr) {}
    int val;
    ListNode *next;
    static void print_node_val(const ListNode *p_node)
    {

        while (p_node != nullptr)
        {
            cout << p_node->val;
            p_node = p_node->next;
            if (p_node)
            {
                cout << "->";
            }
            else
            {
                cout << ";";
            }
        }
        cout << endl;
    }
};

//############################################//
//################   example1   ####################//
//############################################//
// Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element
// appear only once. For example, Given 1->1->2, return 1->2. Given 1-
// >1->2->3->3, return 1->2->3.
namespace example1
{
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        //head is sorted list
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *node = head; //为什么要用一个新的节点: 因为如果用head, 你想用就没机会了
        while (node->next != nullptr)
        {
            //如果当前节点的值等于下一个节点的值
            if (node->val == node->next->val)
            {
                //保存下一个节点的指向
                ListNode *temp = node->next;
                node->next = node->next->next;
                delete temp;
            }
            else
            {
                node = node->next;
            }
        }
        return head;
    }
};
} // namespace example1

//############################################//
//################   example2   ####################//
//############################################//
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3
//注意要把相同都给删了
//因此需要建一个节点，节点的next指向头结点，这样才能处理删除头的情况
namespace example2
{
class Solution
{
public:
    ListNode *deleteDuplicate(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head; //创建一个节点指向第一个节点，可以统一处理第一个节点的特殊情况
        ListNode *node = dummy;
        while (node->next != nullptr && node->next->next != nullptr)
        {
            // cout << "while" <<endl;
            if (node->next->val == node->next->next->val)
            {
                int pre_val = node->next->val;
                while (node->next != nullptr && pre_val == node->next->val)
                {
                    ListNode *temp = node->next;
                    node->next = node->next->next;
                    delete temp;
                }
            }
            else
            {
                node = node->next;
            }
        }
        cout << "good" << endl;
        return dummy->next;
    }
};
} // namespace example2

//############################################//
//################   example3   ####################//
//############################################//
// Partition List 给定一个链表，然后给一个数值x，小于x的在左边，大于或等于x的在右边
// Given a linked list and a value x, write a function to reorder this list
// such that all nodes less than x come before the nodes greater than or
// equal to x.
// 解题分析：将list分成两部分，但两部分的head节点连是不是null都不确定。但总
// 是可以创建两个dummy节点然后在此基础上append，这样就不⽤处理边界条件
// 了。
namespace example3
{
    class Solution{
    public:
        ListNode* partition(ListNode* head, int x){
            if(head == nullptr) return nullptr;
            ListNode* dummy_left = new ListNode(0);
            ListNode* left = dummy_left;
            ListNode* dummy_right = new ListNode(0);
            ListNode* right = dummy_right;
            while(head){
                if(head->val < x){
                    left->next = head;
                    left = left->next;
                }
                else{
                    right->next = head;
                    right = right->next;
                }
                head = head->next;
            }
            right->next = nullptr;
            left->next = dummy_right->next;
            delete dummy_right;
            return dummy_left->next;
        }
    };
    
} // namespace example3

//############################################//
//################   这里主要是指针的追赶问题   ####################//
//############################################//
// 第一个问题：
// Middle Point
// Find the middle point of linked list.
// 解题分析： 寻找特定位置， runner以两倍速前进， chaser ⼀倍速，当runner到
// 达tail时， chaser即为所求解

// 第二个问题：找倒数第k个链表的值
// kth to Last element
// Find the kth to last element of a singly linked list
// 解题分析： 之前类似。只是runner与chaser以相同倍速前进，但runner提前k步
// 出发
namespace example4
{
    class Solution{
    public:
        ListNode* midPoint(ListNode* head){
            if(head == nullptr) return nullptr;
            ListNode* runner = head;
            ListNode* chaser = head;
            while(runner->next && runner->next->next){
                runner = runner->next->next;
                chaser = chaser->next;
            }
            return chaser;
        }

        ListNode* findkthtoLast(ListNode* head, int k){
            ListNode* runner = head;
            ListNode* chaser = head;

            if(head == nullptr || k < 0){
                return nullptr;
            }

            for(int i = 0; i < k; ++i){
                runner = runner->next;
            }
            if(runner == nullptr){
                return nullptr;
            }
            while(runner->next){ //为什么要判断next，因为如果下一个next为空，这时候刚好就是倒数第k个了
                runner = runner->next;
                chaser = chaser->next;
                
            }
            return chaser;
        }
    };
    
} // namespace example4



int main(int argc, char *argv[])
{
    //############################################//
    //################   创建链表   ####################//
    //############################################//

    // cout << l1.next << endl;
    // cout << l2.next << endl;
    // cout << l3.next << endl;
    // cout << (l3.next == nullptr) << endl; //当不初始化的时候, next是不会为nullptr的
    // cout << l3.next->val << endl;

    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(4);
    ListNode *l4 = new ListNode(8);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    // cout << l3->next << endl;
    ListNode::print_node_val(l1);

    // example1::Solution sln;
    // l1 = sln.deleteDuplicates(l1);
    // ListNode::print_node_val(l1);

    // example2::Solution sln2;
    // ListNode *deleted_list = sln2.deleteDuplicate(l1);
    // ListNode::print_node_val(deleted_list);

    // example3::Solution sln3;
    // ListNode* p_list = sln3.partition(l1, 6);
    // ListNode::print_node_val(p_list);

    example4::Solution sln4;
    ListNode* p_min = sln4.midPoint(l1);
    cout << p_min->val << endl;
    cout << endl;

    ListNode* k_p = sln4.findkthtoLast(l1,1);
    cout << k_p->val << endl;

    return 0;
}
