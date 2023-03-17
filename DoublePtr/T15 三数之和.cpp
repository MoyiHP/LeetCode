#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if (nums.size() < 3)
        {
            return vector<vector<int>>();
        }

        // ����
        sort(nums.begin(), nums.end());
    
        // �����
        vector<vector<int>> res;
    
        // ����ָ�� i + [left, right]
        for (int i = 0; i <= nums.size() - 3; i++)
        {
            // ��nums[i]ȥ�� ���ɣ�x + [x,x,....] ��һ��x���Ѿ���������Ԫ������1,2,3��x�����п����� 
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) 
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    res.emplace_back(vector<int>{ nums[i], nums[left], nums[right] });
                    
                    // nums[i],nums[left],nums[right] �Ѽ�¼
                    // Ӧ���ų������뵱ǰ��ͬ��Ԫ��
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};