#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
private:
    // ��N�任Ϊ�����λ�õ�ƽ����
    int transform(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            int i = n % 10;
            ans += i * i;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) 
    {
        // �任�����г��ֹ�������
        unordered_set<int> nums;
        while (true)
        {
            // �任�����г�����1 �ж�Ϊ������
            if (n == 1)
            {
                return true;
            }

            // �任�����г�����ѭ��������ǰ��֮ǰ���ֹ��ˣ����ж�Ϊ�ǿ�����
            if (nums.find(n) != nums.end())
            {
                return false;
            }

            // ��ǰ�޷��ж� �򽫵�ǰ����¼ Ȼ������任
            nums.insert(n);
            n = transform(n);
        }
    }
};

int main()
{
    int n = 2;
    Solution so;
    bool ans = so.isHappy(n);
    cout << n << " " << ans;
    return 0;
}