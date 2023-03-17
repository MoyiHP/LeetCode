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

        // ��ȡ�ո�����������s
        int count = 0;
        for (char& ch : s)
        {
            count += (ch == ' ');
        }
        s.resize(s.size() + 2 * count);

        // ˫ָ�����
        // i = raw_size - 1 ����һ�������Ԫ�أ�(i, raw_size-1] ���Ѿ����Ԫ������
        // j = new_size - 1 ����һ������дԪ�ص�Ԥ���ռ䣬��j, new_size-1] ���Ѿ���д��Ԫ������
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