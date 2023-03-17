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
        // �߽������ж�
        if (head == nullptr || head->next == nullptr) return head;

        // ������������� ��ô����������תhead�Ժ������ 
        ListNode* rHead = reverseList(head->next);
        
        /* ��ת����������Ӧ��Ϊ
        [head] -> [2] <- [3] <- [4] ... <- [rHead]
        ����[2].next = nullptr
        */

        head->next->next = head;
        head->next = nullptr;

        return rHead;
    }
};