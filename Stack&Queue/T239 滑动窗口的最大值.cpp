#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution 
{
	class HumQueue
	{
	private:
		// deque ��Ϊ�ײ����ݴ洢���������Ϊback�����г���Ϊfront
		deque<int> de;
	public:
		HumQueue(){};
		~HumQueue(){};
		
		// ѹ��Ԫ��ʱ �����������Ԫ�أ����ֽ����Ԫ�ص���
		void push(int x)
		{
			while (!de.empty() && x > de.back())
			{
				de.pop_back();
			}

			de.push_back(x);
		}

		// ����Ԫ��ʱ ֻ�ܵ������г��ڴ���Ԫ��
		void pop(int x)
		{
			if (!de.empty() && de.front() == x)
			{
				de.pop_front();
			}
		}
		
		// ��ȡ����ͷԪ��
		int front()
		{
			if (de.empty())
			{
				return 0;
			}
			
			return de.front();
		}
	};

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
		vector<int> res;
		HumQueue hq;
		
		// �������ڵĹ��� [i, i + k - 1] ��ʼΪ [0, k-1]
		for (int i = 0; i < k; i++)
		{
			hq.push(nums[i]);
		}
		res.push_back(hq.front());

		// �����Թ��� 
		for (int i = k; i < nums.size(); i++)
		{
			hq.push(nums[i]);
			hq.pop(nums[i - k]);

			res.push_back(hq.front());
		}

		return res;
    }
};