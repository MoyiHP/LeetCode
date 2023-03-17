#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        // index = hash(element.ascii - 'a')
        int record['z' - 'a' + 1] = { 0 };
        // record s
        for (char e : s)
        {
            record[e - 'a']++;
        }
        // re record t
        for (char e : t)
        {
            record[e - 'a']--;
        }
        // record should all zero
        for (int i : record)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
};