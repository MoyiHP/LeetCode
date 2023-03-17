#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // 写法一:
        // 定义target的搜索区间为[left,right],那么当mid满足条件时，左右区间为[left,mid-1],[mid+1,right]
        //int left = 0;
        //int right = nums.size() - 1;
        //while (left <= right)
        //{
        //    int mid = (left + right) / 2;
        //    if (nums[mid] > target)  // target在左区间
        //    {
        //        right = mid - 1;
        //    }
        //    else if (nums[mid] < target) // target在右区间
        //    {
        //        left = mid + 1;
        //    }
        //    else
        //    {
        //        return mid;
        //    }
        //}
        //return right + 1; // 这里需要手动分析下循环终止后的状态和结果的对应关系  

        // 写法二 ：
        // 定义 target 在 [left,right) 区间中搜索,当mid不满足条件时，左区间为[left,mid),右区间为[mid+1,right)
        int left = 0;
        int right = nums.size();
        while (left<right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)     // target在左边区间
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return right;
    }
};