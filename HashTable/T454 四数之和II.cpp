#include <vector>
#include <unordered_map>
using namespace std;

    class Solution 
    {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
        {
            // map : nums[i] + nums[j] ==> ���ܵ� i j �����
            unordered_map<int, int> map;
            for (int num1 : nums1)
            {
                for (int num2 : nums2)
                {
                    map[num1 + num2]++;
                }
            }

            int ans = 0;
            for (int num3 : nums3)
            {
                for (int num4 : nums4)
                {
                    // ������ nums1[i] + nums2[j] + nums3[k] + nums4[l] = 0 �� nums1[i] + nums2[j] = - (nums3[k] + nums4[l]) �������
                    if (map.find(0 - (num3 + num4)) != map.end())
                    {
                        ans += map[0 - (num3 + num4)];
                    }
                }
            }
        
            return ans;
        }
    };