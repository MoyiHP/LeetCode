#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
private:
    // 将N变换为其各个位置的平方和
    int transform(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            int i = n % 10;
            ans += i * i;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) 
    {
        // 变换过程中出现过的数字
        unordered_set<int> nums;
        while (true)
        {
            // 变换过程中出现了1 判定为快乐数
            if (n == 1)
            {
                return true;
            }

            // 变换过程中出现了循环（即当前数之前出现过了），判定为非快乐数
            if (nums.find(n) != nums.end())
            {
                return false;
            }

            // 当前无法判定 则将当前数记录 然后继续变换
            nums.insert(n);
            n = transform(n);
        }
    }
};

int main()
{
    int n = 2;
    Solution so;
    bool ans = so.isHappy(n);
    cout << n << " " << ans;
    return 0;
}