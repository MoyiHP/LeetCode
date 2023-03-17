#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#include <map>


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sorted string ==> vector<string>
        std::unordered_map<string, vector<string>> map;
        // add all strs to map
        for (string& str : strs)
        {
            string rStr = str;
            sort(str.begin(), str.end());
            map[str].emplace_back(rStr);
        }
        // return all
        vector<vector<string>> ans;
        for (auto& e : map)
        {
            ans.emplace_back(e.second);
        }
     
        return ans;
    }
};