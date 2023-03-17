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


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dmHead = new ListNode(0, head);

        ListNode* slow = dmHead;
        ListNode* fast = dmHead;

        // fast 先移动 n 步
        while ( n-- && fast != nullptr)
        {
            fast = fast->next;
        }

        // slow 和 fast 再一起移动 直到fast移动到末尾结点
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // 此时slow在倒数第N+1个结点处
        slow->next = slow->next->next;

        head = dmHead->next;
        delete dmHead;

        return head;
    }
};