#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        // i 是下一个等待交换的元素，其从0开始向后移动
        // j 是下一个等待交换的元素，其从size-1开始向前移动
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};