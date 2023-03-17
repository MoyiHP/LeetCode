#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/*方法一 使用unordered_map记录出现次数*/
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
//    {
//        // nums1各个元素 ==> 出现次数
//        unordered_map<int, int> map1;
//        for (int item : nums1)
//        {
//            map1[item]++;
//        }
//
//        // 遍历nums2 如果该元素有在map1中出现 则记录到ans中 并且在map1中将对应的次数-1
//        vector<int> ans;
//        for (int item : nums2)
//        {
//            if (map1.find(item) != map1.end() && map1[item] > 0)
//            {
//                ans.emplace_back(item);
//                map1[item]--;
//            }
//        }
//
//        return ans;
//    }
//};

/*方法二 直接排序后使用STL SET求交集算法*/
/*class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        ans.resize(min(nums1.size(), nums2.size()));
        auto itEnd = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ans.begin());
        return vector<int>(ans.begin(), itEnd);
    }
}*/;

class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        ans.resize(min(nums1.size(), nums2.size()));

        // 这里自己写一下双指针法求已经排序的集合的交集的算法
        // 实际上 set_intersection 就是采用的双指针法
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin(), itDst = ans.begin();
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 == *it2) 
            {
                *itDst = *it1;
                itDst++; it1++; it2++;
            }
            else
            {
                if (*it1 < *it2)
                {
                    it1++;
                }
                else
                {
                    it2++;
                }
            }
        }

        return vector<int>(ans.begin(), itDst);
    }
};


int main()
{
    vector<int> nums1 = { 4,9,5,8,4 };
    vector<int> nums2 = { 9,4,9,8,4 };
    Solution so;
    vector<int> ans = so.intersect(nums1, nums2);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}