#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
        int left = 0, right = x , ans = x ;
        // 采用[l,r]
        // 不是说找mid*mid=x的，因为x不是平方数，而是找0 ~ x中平方后最后一个小于等于x的
        while (left <= right)
        {
            int mid = left + (right - left) / 2 ;
            if(mid*mid <= x)    // 当前数小于等于x,有没有可能更大呢，查找范围为[mid+1,right]
            {
                left = mid + 1;
                ans = mid;
            }
            else                // 当前数大于x,应该小一点，查找范围为[l,mid-1]
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};