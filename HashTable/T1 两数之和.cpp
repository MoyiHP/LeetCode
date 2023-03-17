#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // 元素 ==> 出现的位置
        unordered_map<int, int> map;
        int index = 0, size = nums.size();
        for (index = 0; index <= size - 1; index++)
        {
            // 查找 target - nums[index] 是否在之前有出现
            if (map.find(target - nums[index]) != map.end())
            {
                // 有出现 返回对应的值
                vector<int> ans;
                ans.emplace_back(index);
                ans.emplace_back(map[target - nums[index]]);
                return ans;
            }
            
            // 否则存储当前元素 然后继续查找
            map[nums[index]] = index;
        }

        return vector<int>();
    }
};

int main()
{
    vector<int> nums{ 3,2,4 };
    int target = 6;
    Solution so;
    vector<int> ans = so.twoSum(nums, target);
    for (int item : ans)
    {
        cout << item << " ";
    }
    return 0;
}