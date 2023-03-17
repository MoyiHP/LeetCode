#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) 
//    {
//        ListNode* pre = nullptr;
//        ListNode* cur = head;
//        ListNode* next = nullptr;
//
//        while (cur != nullptr)
//        {
//            next = cur->next;
//            
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//
//        return pre;
//    }
//};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        // 边界条件判断
        if (head == nullptr || head->next == nullptr) return head;

        // 如果本函数可行 那么可以用来翻转head以后的链表 
        ListNode* rHead = reverseList(head->next);
        
        /* 翻转后的链表情况应该为
        [head] -> [2] <- [3] <- [4] ... <- [rHead]
        其中[2].next = nullptr
        */

        head->next->next = head;
        head->next = nullptr;

        return rHead;
    }
};