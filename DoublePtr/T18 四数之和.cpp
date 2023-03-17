#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4)
        {
            return vector<vector<int>>();
        }

        // 排序
        sort(nums.begin(), nums.end());

        // 结果集
        vector<vector<int>> res;

        // 遍历指针 i + j + [left, right]
        for (int i = 0; i <= nums.size() - 4; i++)
        {
            // 做一个剪枝 因为是排序过的 如果nums[i] > taget && nums[i] >= 0 那么就可能有结果了
            if (nums[i] >= 0 && nums[i] > target)
            {
                continue;
            }

            // 对nums[i]去重 理由：x + [x,x,....] 第一个x就已经考虑了三元组中有1,2,3个x的所有可能了 
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 遍历指针 i + j + [left, right]
            for (int j = i + 1; j <= nums.size() - 3; j++)
            {
                // 同理 可以做去重
                if (nums[i] >= 0 && nums[i] + nums[j] > target)
                {
                    continue;
                }


                // 对nums[j]去重 理由与上述对nums[i]去重类似
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                // 遍历[left, right]
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    // 这里注意用int会发生溢出 
                    long long int sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        // 对left, right去重
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
        }

        return res;
    }
};