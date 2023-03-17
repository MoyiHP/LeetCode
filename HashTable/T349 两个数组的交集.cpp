#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> ans;
        // 找到在nums1中出现过的nums2的元素
        unordered_set<int> set1(nums1.begin(), nums1.end());
        for (int item : nums2)
        {
            if (set1.find(item) != set1.end())
                ans.insert(item);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

int main()
{
    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };
    Solution so;
    vector<int> ans = so.intersection(nums1, nums2);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}