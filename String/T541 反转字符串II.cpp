#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        string::iterator itStart = s.begin(), itEnd =s.end();
        for (int i = 0; i <= (int)s.size() - 1  ; i += (2 * k))
        {
  
            itStart = s.begin() + i;

            if (i + k <= s.size())
            {
                itEnd = s.begin() + i + k;
            }
            else
            {
                itEnd = s.end();
            }

           
            reverse(itStart, itEnd);
        }
        return s;
    }
};

//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        for (int i = 0; i < s.size(); i += (2 * k)) {
//            // 1. 每隔 2k 个字符的前 k 个字符进行反转
//            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
//            if (i + k <= s.size()) {
//                reverse(s.begin() + i, s.begin() + i + k);
//            }
//            else {
//                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
//                reverse(s.begin() + i, s.end());
//            }
//        }
//        return s;
//    }
//};
int main()
{
    string s = "";
    int k = 2;
    Solution so;
    string res = so.reverseStr(s, k);
    cout << res;

    // cout << (0 <= -1);
    return 0;
}