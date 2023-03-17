#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> getNext(string s)
    {
        vector<int> next(s.size());
        next[0] = 0;

        for (int i = 1, j = 0; i < s.size(); i++)
        {
            while (j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }

            if (s[j] == s[i])
            {
                j++;
            }

            next[i] = j;
        }

        return next;
    }

public:
    // ·½·¨1
    //bool repeatedSubstringPattern(string s) 
    //{
    //    string str = s + s;
    //    str.erase(str.begin());
    //    str.erase(str.end()-1);
    //    int pos = str.find(s);
    //    return (str.find(s) != string::npos);
    //}

    bool repeatedSubstringPattern(string s)
    {
        vector<int> next = getNext(s);
        int len = next.back();
        return len != 0 && s.size() % (s.size() - len) == 0;
    }
};

int main()
{
    string s = "abab";
    cout << Solution().repeatedSubstringPattern(s) << endl;
    return 0;
}