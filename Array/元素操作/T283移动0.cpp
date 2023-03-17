#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        if(nums.size() <= 1)
        {
            return;
        }

        // 采用双指针法
        // [0,slowPtr)为非0元素
        // [0,fastPtr)为已经扫描元素，fastPtr指向当前扫描元素
        int slowPtr = 0 , fastPtr = 0;
        for(fastPtr = 0; fastPtr <= nums.size() - 1; fastPtr++)
        {
            if(nums[fastPtr] != 0)
            {
                nums[slowPtr] = nums[fastPtr];
                slowPtr++;
            }
        }

        // 
        for(; slowPtr <= nums.size() - 1; slowPtr++)
        {
            nums[slowPtr] = 0;
        }
    }
};