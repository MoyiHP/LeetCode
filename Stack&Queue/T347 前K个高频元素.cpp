#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;

        // num ==> Ƶ��
        map<int, int> m;
        for (int& num : nums)
        {
            m[num]++;
        }

        // Ƶ�ʵ�����
        // pq ==> �洢<nums,Ƶ��> ==> ������� ��Ƶ������
        struct Comp
        {
            bool operator()(const pair<int, int>& first, const pair<int, int>& second)
            {
                return first.second < second.second;
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
        for (auto item : m)
        {
            pq.push(item);
        }

        // ���ǰk��
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};

int main()
{
    Solution so;
    vector<int> nums{ 1,1,1,2,2,3 };
    int k = 2;
    vector<int> res = so.topKFrequent(nums, k);
    for (int& i : res)
    {
        cout << i << " ";
    }
    return  0;
}