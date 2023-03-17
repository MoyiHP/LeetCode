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

        // ��fastָ������ڳ����Ŀ�ͷ slowָ������ڶ����Ŀ�ͷ
        ListNode* fast = lenA > lenB ? headA : headB;
        ListNode* slow = lenA > lenB ? headB : headA;
       
        // fastָ������lenA-lenB����
        int n = abs(lenA - lenB);
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }

        // �������ͬʱ�н���ֱ���������λ��
        while (fast != slow && fast != nullptr && slow != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // ������������ �ҷǿ�
        return fast;
    }
};