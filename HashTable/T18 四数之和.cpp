#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        
        int len = nums.size();
        if (len < 4)
        {
            return result;
        }
        sort(nums.begin(), nums.end());

        // a = nums[i] b = nums[j] c = nums[left] d = nums[right]
        int i = 0, j = i + 1, left = j + 1, right = len - 1;
        for (i = 0; i <= len - 4; i++)
        {
            // 去重i
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (j = i + 1; j <= len - 3; j++)
            {
                // 去重j
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                // 双指针找到left right
                left = j + 1;
                right = len - 1;
                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else // = 0 
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        // 去重
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++; right--;
                    }
                }
            }
        }
        
        return result;
    }
};

int main()
{
    vector<int> nums{ 1000000000,1000000000,1000000000,1000000000 };
    int target = 0;
    vector<vector<int>> result;
    Solution so;
    result = so.fourSum(nums, target);
    for (vector<int>& vec : result)
    {
        cout << "[";
        for (int& num : vec)
        {
            cout << num << " ";
        }
        cout << "]";
    }
    return 0;
}