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
            // ������һ������
            if (s[fast] != ' ') 
            {
                // ������ǵ�һ������ �������һ���ո�
                if (slow != 0)
                {
                    s[slow] = ' ';
                    slow++;
                }
                // ��������������
                while (fast < len && s[fast] != ' ')
                {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        
        // ������ɵ��ַ�������Ϊ slow + 1
        s.resize(slow);
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
        // 1. ȥ�ض���Ŀո�
        deleteRedundantSpace(s);
        // 2. ��ת�����ַ���
        reverseString(s, 0, s.size() - 1);
        // 3. ��ת����
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