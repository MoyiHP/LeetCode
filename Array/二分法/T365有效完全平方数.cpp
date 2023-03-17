#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        // 暴力 ： 0 ~ num 找有没有满足 x * x = num 的
        // 二分
        int left = 0, right = num;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(mid * mid == num)
            {
                return true;
            }
            else if(mid * mid > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};