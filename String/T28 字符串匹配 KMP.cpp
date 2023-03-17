#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    // ��ȡKMP next���� - ����ֱ�Ӳ���ǰ׺����Ϊnext����
    // ��ʱ next[x] �������� needle[0,x]������ǰ��׺�ĳ���Ϊnext[x]������ǰ׺��ĩβ�ַ�Ϊneedle[next[x]-1]
    // ����needle ģʽ�� 
    vector<int> getNext(string needle)
    {
        // j Ϊǰ׺����ĩβ ǰ׺��[0,j]
        int j = 0;
        // i Ϊ��׺����ĩβ ��׺��[i-j,i]
        int i = 1;

        // ��ʼ�� �趨�����е����ַ����ַ���������ǰ��׺�ĳ���Ϊ0
        vector<int> next(needle.size());
        next[0] = 0;

        // ��ʼ���� ǰ��[0,j]�Ѿ�������� ���ڼ���i�Լ���next[i]
        for (i = 1; i < needle.size(); i++)
        {
            // WHEN needle[j] != needle[i]
            /* 
            ��Ϊ [0,j-1] & [i-j, i-1] �� [0,i-1] ������ǰ��׺��
            ����Ŀǰ��Ҫ������ [0,j-1]��ǰ׺ �� [i-j, i-1]�ĺ�׺ ���ҵ������ȵ���������ʹ�� [0,x] == [i-x-1, i-x] �� needle[x+1] == needle[i]
            ����Ϊ [0,j-1] == [i-j, i-1]�� ���� [0,x] == [i-x-1, i-x] �ȼ��� [0,x] == [j-x-1, j-1]������Ҫ�ҵľ��� [0,j-1] �е�����ǰ��׺
            ����������Ҫ�ҵ����� [0, j-1] ������ǰ��׺��ǰ׺��λ�� �����Ϣ�Ѿ���next��ǰ����������л�ȡ��
            */
            // TIP1 ���ҵ���[0,x]�����Ծɲ�������needle[x+1]==needle[i] ���Կ�����Ҫ��һ���ظ��������� �ʶ�������Ҫʹ��whileѭ�����
            // TIP2 ע��������Ҫ�� [0,j-1] ˵�� j > 0 �� j==0 �� needle[j] != needle[i] ʱ˵�� [0,i] ������ǰ��׺����Ϊ0 
            while (j > 0 && needle[j] != needle[i])
            {
                j = next[j - 1];
            }

            // WHEN needle[j] == needle[i]
            // ������ һ��ʼ���������� ����˵������ ����ѭ����Ѱ�Һ����������
            // ��Ϊ [0,j-1] & [i-j, i-1] �� [0,i-1] ������ǰ��׺������ [0,j] & [i-j,i] �� [0,i] ������ǰ��׺������Ϊ j+1
            if (needle[j] == needle[i])
            {
                // Ϊ�˱�֤��������֪������j��λ����[0,i-1]������ǰ��׺��ǰ׺��ĩβ�ַ��ĺ�һλ
                j++;
            }
           
            next[i] = j;
        }

        return next;
    }

public:
    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0)
        {
            return 0;
        }

        int ans = -1;
        // ��ȡnext����
        vector<int> next = getNext(needle);

        // i ���ڱ��� haystack; j ���ڱ��� needle
        for (int i = 0, j = 0; i < haystack.size(); i++)
        {
            // ����ʧ��
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            // ƥ������
            if (haystack[i] == needle[j])
            {
                // ���������ƥ��
                if (j == needle.size() - 1)
                {
                    ans = i + 1 - needle.size();
                    break;
                }
                // ���ǵ�����ƥ�� ����������һ���ַ��Ƿ�ƥ��
                else
                {
                    j++;
                }
            }

            //if (haystack[i] == needle[j]) {
            //    j++;
            //}
            //if (j == needle.size()) {
            //    return (i - needle.size() + 1);
            //}

            
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string haystack = "aabaabaaf";
    string needle = "aabaaf";


    cout << "str: " << so.strStr(haystack, needle) << endl;


    return 0;
}
