#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    void deleteRedundantSpace(string& s)
    {
        int slow = 0, fast = 0, len = s.size();
        for(fast = 0 ; fast < len; fast++)
        {
            // 遇到了一个单词
            if (s[fast] != ' ') 
            {
                // 如果不是第一个单词 就先添加一个空格
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }
                // 而后添加这个单词
                while (fast < len && s[fast] != ' ')
                {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        
        // 处理完成的字符串长度为 slow + 1
        s.resize(slow);
    }

    // 反转字符串[start, end]
    void reverseString(string& s, int start, int end)
    {
        int i = start, j = end;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++; j--;
        }
    }

public:
    string reverseWords(string s)
    {
        // 1. 去重多余的空格
        deleteRedundantSpace(s);
        // 2. 反转整个字符串
        reverseString(s, 0, s.size() - 1);
        // 3. 反转单词
        int start = 0, end = 0;
        while (end <= s.size())
        {
            if (s[end] == ' ' || end == s.size())
            {
                reverseString(s, start, end - 1);
                start = end + 1;
            }
            
            end++;
        }

        return s;
    }
};

int main()
{
    Solution so;
    string str = "  the   sky is   blue   ";
    cout << "[" << so.reverseWords(str) << "]" << endl;
    return 0;
}