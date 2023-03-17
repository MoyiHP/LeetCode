#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) 
    {
        // 1. �����Ի�ȡ�ո��ַ�����
        int count = 0;
        for (char& ch : s)
        {
            count += (ch == ' ');
        }

        // 2. s ������ݹ��� 2 * count
        s.resize(s.size() + 2 * count);

        // 3. ָ��iti��ԭ�������һ���ַ���λ�ÿ�ʼ���Ӻ���ǰ����
        // ͬʱָ��itj�����ڵ����Ŀ�λ��ʼ���Ӻ���ǰ�����ַ�
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