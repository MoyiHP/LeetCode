#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // record dataType is Array<int, 26>
    using Record = array<int, 26>;

    // to use Record as key in unordered_map, we need a Record_Hasher
    struct Record_Hasher
    {
        size_t operator()(const Record& record) const
        {
            // simply use sum as hash
            if (record.empty())
            {
                return -1;
            }

            int sum = 0;
            for (int i : record)
            {
                sum += i;
            }
            return sum;
        }
    };

    // to calculate Record
    Record GetRecord(string& str)
    {
        Record record;
        record.fill(0);
        for (char& ch : str)
        {
            record[ch - 'a']++;
        }
        return record;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<Record, vector<string>, Record_Hasher> map;
        for (string& str : strs)
        {
            map[GetRecord(str)].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto item : map)
        {
            ans.emplace_back(item.second);
        }

        return ans;
    }
};

int main()
{
    Solution so;
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    so.groupAnagrams(strs);
}