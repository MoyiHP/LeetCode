#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution 
{
private:
    int listLength(ListNode* head)
    {
        int length = 0;
        while (head != nullptr)
        {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        int lenA = listLength(headA);
        int lenB = listLength(headB);

        // 将fast指针放置在长链的开头 slow指针放置在短链的开头
        ListNode* fast = lenA > lenB ? headA : headB;
        ListNode* slow = lenA > lenB ? headB : headA;
       
        // fast指针先走lenA-lenB步骤
        int n = abs(lenA - lenB);
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }

        // 而后二者同时行进，直到二者相等位置
        while (fast != slow && fast != nullptr && slow != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 最后若二者相等 且非空
        return fast;
    }
};