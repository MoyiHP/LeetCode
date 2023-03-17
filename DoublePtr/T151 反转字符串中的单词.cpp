#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void deleteRedundantSpace(string& s)
    {
        // i 为下一个待检测元素 j 为下一个合格元素的待用存储
        int i = 0, j = 0;
        bool isFirst = true;
        for (; i < s.size(); i++)
        {
            // 遇到了单词
            if (s[i] != ' ')
            {
                // 若其不为第一个单词 则添加一个空格
                if (!isFirst)
                {
                    s[j] = ' ';
                    j++;
                }
                else
                {
                    isFirst = false;
                }

                // 而后写完这个单词
                while (i < s.size() && s[i] != ' ')
                {
                    s[j] = s[i];
                    j++;
                    i++;
                }
            }
        }

        // 最后结束时 [0, j)为处理后的字符串，其长度为j
        s.resize(j);
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
        // 1. deleteRedundantSpace
        deleteRedundantSpace(s);

        // 2. reverse s
        reverseString(s, 0, s.size() - 1);

        // 3. reverse words
        int start = 0, end = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() ||  s[i] == ' ')
            {
                end = i - 1;
                reverseString(s, start, end);
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{
    Solution so;
    string str = "the sky is blue";
    cout <<"[" << so.reverseWords(str) << "]";
}