#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Ԫ�� ==> ���ֵ�λ��
        unordered_map<int, int> map;
        int index = 0, size = nums.size();
        for (index = 0; index <= size - 1; index++)
        {
            // ���� target - nums[index] �Ƿ���֮ǰ�г���
            if (map.find(target - nums[index]) != map.end())
            {
                // �г��� ���ض�Ӧ��ֵ
                vector<int> ans;
                ans.emplace_back(index);
                ans.emplace_back(map[target - nums[index]]);
                return ans;
            }
            
            // ����洢��ǰԪ�� Ȼ���������
            map[nums[index]] = index;
        }

        return vector<int>();
    }
};

int main()
{
    vector<int> nums{ 3,2,4 };
    int target = 6;
    Solution so;
    vector<int> ans = so.twoSum(nums, target);
    for (int item : ans)
    {
        cout << item << " ";
    }
    return 0;
}