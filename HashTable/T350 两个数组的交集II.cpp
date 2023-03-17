#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/*����һ ʹ��unordered_map��¼���ִ���*/
//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
//    {
//        // nums1����Ԫ�� ==> ���ִ���
//        unordered_map<int, int> map1;
//        for (int item : nums1)
//        {
//            map1[item]++;
//        }
//
//        // ����nums2 �����Ԫ������map1�г��� ���¼��ans�� ������map1�н���Ӧ�Ĵ���-1
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

/*������ ֱ�������ʹ��STL SET�󽻼��㷨*/
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

        // �����Լ�дһ��˫ָ�뷨���Ѿ�����ļ��ϵĽ������㷨
        // ʵ���� set_intersection ���ǲ��õ�˫ָ�뷨
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