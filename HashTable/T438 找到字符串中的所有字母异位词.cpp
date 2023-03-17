#include <unordered_map>
#include <vector>
#include <string>

#include <iostream>
using namespace std;

class Solution {
public:
    class Record
    {
    private:
        unordered_map<char, int> data;  // �ַ���Ӧ�ļ���
        int diff;                       // ��Ϊ0���ַ�����
    public:
        Record(){}
        void Put(char ch) 
        {
            data[ch]++;
            if (data[ch] == 0)   // (-1 to 0)
            {
                diff--;
            }
            else if (data[ch] == 1)  // (0 to 1)
            {
                diff++;
            }
        }

        void Get(char ch)
        {
            data[ch]--;
            if (data[ch] == 0)   // (1 to 0)
            {
                diff--;
            }
            else if (data[ch] == -1) // (0 to -1)
            {
                diff++;
            }
        }

        bool OK()
        {
            return diff == 0;
        }
    };

    vector<int> findAnagrams(string s, string p) 
    {
        // ��ĸ��λ�ʵĳ��ȱض���һ�µ�
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen)
        {
            return vector<int>();
        }
    
        // ����ͳ��P
        Record record;
        for (char ch : p)
        {
            record.Put(ch);
        }

        // �������ڷ�
        // �����и�ǰ������ �� ����ĸ��λ�ʵĳ��ȱض���һ�µġ�
        // ���Ի������ڵķ�Χ�� [start, start + pLen - 1], start <= sLen - pLen
        int start = 0;
        vector<int> ans;

        // �ȿ���ʼ����λ��
        for (int i = start; i <= start + pLen - 1; i++)
        {
            record.Get(s[i]);
        }
        if (record.OK())
        {
            ans.push_back(start);
        }

        while (start < sLen - pLen)
        {
            record.Put(s[start]);
            record.Get(s[start + pLen]);
            start++;

            if (record.OK())
            {
                ans.push_back(start);
            }
        }

        return ans;
    }
};

int main()
{
    string s = "cbcb";
    string p = "cb";
    Solution so;
    vector<int> ans = so.findAnagrams(s, p);
    for (int& i : ans)
    {
        cout << i << " ";
    }
    return 0;
}