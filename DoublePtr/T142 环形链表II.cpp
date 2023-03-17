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
		
		// Floyid 判圈
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;

			// 判断有环 进一步寻找入环点
			if (slow == fast)
			{
				ListNode* ptr = head;
				// 同步行进直至相遇即为入环点
				while (slow != ptr)
				{
					slow = slow->next;
					ptr = ptr->next;
				}

				return ptr;
			}
		}

		// 判断无环
		return nullptr;
	}
};