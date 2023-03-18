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

        // num ==> 频率
        map<int, int> m;
        for (int& num : nums)
        {
            m[num]++;
        }

        // 频率的排序
        // pq ==> 存储<nums,频率> ==> 排序规则 按频率排序
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

        // 输出前k个
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