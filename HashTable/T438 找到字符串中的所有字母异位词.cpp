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
        unordered_map<char, int> data;  // 字符对应的计数
        int diff;                       // 不为0的字符总数
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
        // 字母异位词的长度必定是一致的
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen)
        {
            return vector<int>();
        }
    
        // 首先统计P
        Record record;
        for (char ch : p)
        {
            record.Put(ch);
        }

        // 滑动窗口法
        // 这里有个前置条件 ： “字母异位词的长度必定是一致的”
        // 所以滑动窗口的范围是 [start, start + pLen - 1], start <= sLen - pLen
        int start = 0;
        vector<int> ans;

        // 先看初始放置位置
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