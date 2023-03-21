#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// �ݹ鷽��
class Solution 
{
public:
    /* �ݹ���Ҫ��
    * 1. ��������¼���� ��ǰ��� ��ǰ���
    * 2. ��ֹ���������ʵ��ս��
    * 3. �����߼������ʵ�ǰ��㣬��ֵ��ӵ���¼���飬�ݹ�����²��㣬��ȼ�һ
    */
    void traversal(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        // ��ֹ����
        if (cur == nullptr) return;

        // ���㴦��
        if (result.size() == depth) result.emplace_back(vector<int>()); // �����ʵ�ÿ����������ʱ ��Ҫ�����¼����
        result[depth].push_back(cur->val);

        // �ݹ��߼�
        traversal(cur->left, result, depth + 1);
        traversal(cur->right, result, depth + 1);
    }


    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        traversal(root, result, 0);
        return result;
    }
};

// ��������
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr) return vector<vector<int>>();
        
        vector<vector<int>> result;
        queue<TreeNode*> que;
        
        // ��ǰ����
        int depth = 0;
        result.emplace_back(vector<int>());
        que.push(root);
        // ʹ��nullptr��Ϊÿ������ı�� ��ÿ�α������� ���ٴ����
        que.push(nullptr);


        while (que.size() > 1)
        {
            TreeNode* cur = que.front();
            que.pop();

            if (cur != nullptr)
            {
                result[depth].push_back(cur->val);

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            else
            {
                depth++;
                result.emplace_back(vector<int>());
                que.push(nullptr);
            }
        }

        return result;
    }
};