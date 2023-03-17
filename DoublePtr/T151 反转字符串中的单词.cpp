#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void deleteRedundantSpace(string& s)
    {
        // i Ϊ��һ�������Ԫ�� j Ϊ��һ���ϸ�Ԫ�صĴ��ô洢
        int i = 0, j = 0;
        bool isFirst = true;
        for (; i < s.size(); i++)
        {
            // �����˵���
            if (s[i] != ' ')
            {
                // ���䲻Ϊ��һ������ �����һ���ո�
                if (!isFirst)
                {
                    s[j] = ' ';
                    j++;
                }
                else
                {
                    isFirst = false;
                }

                // ����д���������
                while (i < s.size() && s[i] != ' ')
                {
                    s[j] = s[i];
                    j++;
                    i++;
                }
            }
        }

        // ������ʱ [0, j)Ϊ�������ַ������䳤��Ϊj
        s.resize(j);
    }

    // ��ת�ַ���[start, end]
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