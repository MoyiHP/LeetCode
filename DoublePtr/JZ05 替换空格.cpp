#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s)
    {
        if (s.size() == 0) return s;
        int i = s.size() - 1;

        // 获取空格数量以扩充s
        int count = 0;
        for (char& ch : s)
        {
            count += (ch == ' ');
        }
        s.resize(s.size() + 2 * count);

        // 双指针遍历
        // i = raw_size - 1 是下一个待检测元素，(i, raw_size-1] 是已经检测元素区间
        // j = new_size - 1 是下一个待填写元素的预留空间，（j, new_size-1] 是已经填写的元素区域
        int j = s.size() - 1;
        for (; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
            }
            else
            {
                s[j] = s[i];
                j--;
            }
        }

        return s;
    }
};

int main()
{
    string str = "we are happy.";
    Solution so;
    cout << so.replaceSpace(str) << endl;

    return 0;
}