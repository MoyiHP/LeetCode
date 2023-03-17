#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int len = nums.size();
        // a = nums[i] b = nums[left] c = nums[right]
        int i = 0, left = i + 1, right = len - 1;
        for (i = 0; i <= len - 3; i++)
        {
            /* 这里去重的逻辑：
            1. 对于可能的 ... x , ... , x , ... 的情况，当考虑 第一个x时将会同步计算所有的
               三元组中有 1 2 3 个x的可能，而如果考虑的是最后一个x 则只计算了三元组中只有一个
               x的可能
            2. 那么很显然 需要考虑到所有有1 2 3个x的三元组 同时需要去重 所以这里只考虑第一个x
               即可
            */
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 使用双指针法 从后续的数中挑选出 a + b + c = 0 的 bc组合
            left = i + 1;
            right = len - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else // = 0
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    /* bc去重 */
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                
                    left++; right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = { -2, 1,1,1,1 };
    Solution so;
    vector<vector<int>> ans = so.threeSum(nums);
    for (vector<int>& posIJK : ans)
    {
        cout << "[";
        for (int& i : posIJK)
        {
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}