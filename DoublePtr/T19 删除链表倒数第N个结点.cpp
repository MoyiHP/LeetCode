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

        // fast ���ƶ� n ��
        while ( n-- && fast != nullptr)
        {
            fast = fast->next;
        }

        // slow �� fast ��һ���ƶ� ֱ��fast�ƶ���ĩβ���
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // ��ʱslow�ڵ�����N+1����㴦
        slow->next = slow->next->next;

        head = dmHead->next;
        delete dmHead;

        return head;
    }
};