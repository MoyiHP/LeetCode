#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) 
    {
        // 1. 遍历以获取空格字符数量
        int count = 0;
        for (char& ch : s)
        {
            count += (ch == ' ');
        }

        // 2. s 向后扩容共计 2 * count
        s.resize(s.size() + 2 * count);

        // 3. 指针iti从原来的最后一个字符的位置开始，从后向前遍历
        // 同时指针itj从现在的最后的空位开始，从后向前填入字符
        string::reverse_iterator iti = s.rbegin() + 2 * count, itj = s.rbegin();
        while (iti != s.rend() && itj != s.rend())
        {
            if (*iti == ' ') 
            {
                *itj = '0'; *(itj + 1) = '2'; *(itj + 2) = '%';
                itj += 3;
            }
            else
            {
                *itj = *iti;
                itj++;
            }
            iti++;
        }

        return s;
    }
};

int main()
{
    string s = "a b c";
    s.append('\0');
    cout << s << endl;
    Solution so;
    string res = so.replaceSpace(s);
    cout << res << endl;
    return 0;
}