#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // i ����һ�������Ԫ�� j ����һ���ϸ�Ԫ�ص����λ��
        int i = 0, j = 0;
        for (i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};