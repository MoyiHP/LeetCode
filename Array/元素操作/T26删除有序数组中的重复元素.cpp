#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() <= 1)
        {
            return nums.size();
        }

        // 采用双指针
        // [0,fastPtr) 已经扫描的区域,fastPtr为当前扫描元素
        // [0,slowPtr) 满足条件的区域,不重复元素，由于升序，只要大于上次添加的元素即可
        // 0号元素默认添加
        int fastPtr = 1 , slowPtr = 1 , lastVal = nums[0];
        for(fastPtr = 1; fastPtr <= nums.size() - 1; fastPtr++)
        {
            if(nums[fastPtr] > lastVal)
            {
                nums[slowPtr] = nums[fastPtr];
                lastVal = nums[fastPtr];
                slowPtr++;
            }
        }
        return slowPtr;
    }
};