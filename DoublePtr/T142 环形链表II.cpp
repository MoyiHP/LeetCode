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

class Solution 
{
public:
	ListNode* detectCycle(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}
		
		// Floyid ��Ȧ
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;

			// �ж��л� ��һ��Ѱ���뻷��
			if (slow == fast)
			{
				ListNode* ptr = head;
				// ͬ���н�ֱ��������Ϊ�뻷��
				while (slow != ptr)
				{
					slow = slow->next;
					ptr = ptr->next;
				}

				return ptr;
			}
		}

		// �ж��޻�
		return nullptr;
	}
};