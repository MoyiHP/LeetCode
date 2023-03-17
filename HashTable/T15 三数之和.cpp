#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int len = nums.size();
        // a = nums[i] b = nums[left] c = nums[right]
        int i = 0, left = i + 1, right = len - 1;
        for (i = 0; i <= len - 3; i++)
        {
            /* ����ȥ�ص��߼���
            1. ���ڿ��ܵ� ... x , ... , x , ... ������������� ��һ��xʱ����ͬ���������е�
               ��Ԫ������ 1 2 3 ��x�Ŀ��ܣ���������ǵ������һ��x ��ֻ��������Ԫ����ֻ��һ��
               x�Ŀ���
            2. ��ô����Ȼ ��Ҫ���ǵ�������1 2 3��x����Ԫ�� ͬʱ��Ҫȥ�� ��������ֻ���ǵ�һ��x
               ����
            */
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // ʹ��˫ָ�뷨 �Ӻ�����������ѡ�� a + b + c = 0 �� bc���
            left = i + 1;
            right = len - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else // = 0
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    /* bcȥ�� */
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                
                    left++; right--;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums = { -2, 1,1,1,1 };
    Solution so;
    vector<vector<int>> ans = so.threeSum(nums);
    for (vector<int>& posIJK : ans)
    {
        cout << "[";
        for (int& i : posIJK)
        {
            cout << i << " ";
        }
        cout << "]";
    }
    return 0;
}