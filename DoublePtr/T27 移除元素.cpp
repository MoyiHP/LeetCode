#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // i 是下一个待检查元素 j 是下一个合格元素的填充位置
        int i = 0, j = 0;
        for (i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};