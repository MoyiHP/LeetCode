#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        // i ����һ���ȴ�������Ԫ�أ����0��ʼ����ƶ�
        // j ����һ���ȴ�������Ԫ�أ����size-1��ʼ��ǰ�ƶ�
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};