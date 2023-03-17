#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4)
        {
            return vector<vector<int>>();
        }

        // ����
        sort(nums.begin(), nums.end());

        // �����
        vector<vector<int>> res;

        // ����ָ�� i + j + [left, right]
        for (int i = 0; i <= nums.size() - 4; i++)
        {
            // ��һ����֦ ��Ϊ��������� ���nums[i] > taget && nums[i] >= 0 ��ô�Ϳ����н����
            if (nums[i] >= 0 && nums[i] > target)
            {
                continue;
            }

            // ��nums[i]ȥ�� ���ɣ�x + [x,x,....] ��һ��x���Ѿ���������Ԫ������1,2,3��x�����п����� 
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // ����ָ�� i + j + [left, right]
            for (int j = i + 1; j <= nums.size() - 3; j++)
            {
                // ͬ�� ������ȥ��
                if (nums[i] >= 0 && nums[i] + nums[j] > target)
                {
                    continue;
                }


                // ��nums[j]ȥ�� ������������nums[i]ȥ������
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                // ����[left, right]
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    // ����ע����int�ᷢ����� 
                    long long int sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        // ��left, rightȥ��
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }

        return res;
    }
};