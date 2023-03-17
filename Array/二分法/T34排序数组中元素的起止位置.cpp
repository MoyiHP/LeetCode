#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // 由于数组已经排序，因此整个数组是单调递增的，我们可以利用二分法来加速查找的过程。
        // 考虑target开始和结束位置，其实我们要找的就是数组中「第一个等于target的位置」（记为leftIdx）和「第一个大于target的位置减一」（记为 rightIdx）。
        // 二分查找中，寻找 leftIdx 即为在数组中寻找第一个大于等于target的下标，寻找rightIdx即为在数组中寻找第一个大于target的下标，然后将下标减一。
        // 最后，因为target可能不存在数组中，因此我们需要重新校验我们得到的两个下标是否符合条件，如果符合条件就返回,不符合就返回 [-1,-1]。
        int lb = getLeftBorder(nums,target);
        int rb = getRightBorder(nums,target);
        if((0 <= lb && lb <= rb && rb <= nums.size() - 1) && (nums[lb] == nums[rb] && nums[rb] == target))
        {
            return vector<int>{lb,rb};
        }
        else
        {
            return vector<int>{-1,-1};
        }        
    }

private:
    int getLeftBorder(vector<int>& nums, int target)
    {
        int leftBorder = nums.size() ;
        // 采用[left,right]
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2 ;
            if( nums[mid] >= target)    // 左边界是第一个大于等于target的数,当前数大于等于target，查找范围为[left,mid-1]
            {
                right = mid -1 ;
                leftBorder = mid ;
            }
            else                        // 当前数小于target,查找范围为[mid+1,right]
            {
                left = mid + 1 ;
            }
        }
        return leftBorder;
    }

    int getRightBorder(vector<int>& nums, int target)
    {
         int rightBorder = nums.size() ;
        // 采用[left,right]
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2 ;
            if( nums[mid] > target)    // 右边界是第一个大于target的数,当前数大于target，查找范围为[left,mid-1]
            {
                right = mid -1 ;
                rightBorder = mid ;
            }
            else                        // 当前数小于target,查找范围为[mid+1,right]
            {
                left = mid + 1 ;
            }
        }
        rightBorder --;             // 右边界是第一个大于target的数的上一位
        return rightBorder;
    }
};