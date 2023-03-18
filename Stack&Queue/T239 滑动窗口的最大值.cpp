#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution 
{
	class HumQueue
	{
	private:
		// deque 作为底层数据存储，队列入口为back，队列出口为front
		deque<int> de;
	public:
		HumQueue(){};
		~HumQueue(){};
		
		// 压入元素时 如果其大于入口元素，则现将入口元素弹出
		void push(int x)
		{
			while (!de.empty() && x > de.back())
			{
				de.pop_back();
			}

			de.push_back(x);
		}

		// 弹出元素时 只能弹出队列出口处的元素
		void pop(int x)
		{
			if (!de.empty() && de.front() == x)
			{
				de.pop_front();
			}
		}
		
		// 获取队列头元素
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
		
		// 滑动窗口的构造 [i, i + k - 1] 初始为 [0, k-1]
		for (int i = 0; i < k; i++)
		{
			hq.push(nums[i]);
		}
		res.push_back(hq.front());

		// 滑动以构造 
		for (int i = k; i < nums.size(); i++)
		{
			hq.push(nums[i]);
			hq.pop(nums[i - k]);

			res.push_back(hq.front());
		}

		return res;
    }
};