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

        // 排序
        sort(nums.begin(), nums.end());
    
        // 结果集
        vector<vector<int>> res;
    
        // 遍历指针 i + [left, right]
        for (int i = 0; i <= nums.size() - 3; i++)
        {
            // 对nums[i]去重 理由：x + [x,x,....] 第一个x就已经考虑了三元组中有1,2,3个x的所有可能了 
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
                    
                    // nums[i],nums[left],nums[right] 已记录
                    // 应该排除所有与当前相同的元素
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