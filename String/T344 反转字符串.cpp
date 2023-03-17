#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        if (s.size() == 0)
        {
            return;
        }

        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o', ',' , 'w', 'o', 'r', 'l', 'd', '!'};
    Solution so;
    so.reverseString(s);
    for (char& ch : s)
    {
        cout << ch;
    }
    return 0;
}