#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // 涉及数组元素的操作，如果涉及双循环/区域划分等，可以考虑 【双指针手法/快慢指针】
        // 指针这里实际是区域划分边界
        // [0,fastPtr) 中的元素已经扫描，fastPtr是当前扫描元素；
        // [0,slowPtr) 中的元素是满足条件的元素，slowPtr指向的元素未知
        if(nums.size() == 0 )
        {
            return 0;
        }

        int fastPtr = 0, slowPtr = 0;
        for(fastPtr = 0; fastPtr <= nums.size() - 1; fastPtr++)
        {
            if(nums[fastPtr] != val)
            {
                nums[slowPtr] = nums[fastPtr];
                slowPtr++;
            }
        }
        return slowPtr;
    }
};