#include <iostream>
#include <vector>
#include <stack>
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

// �ݹ鷨
class Solution 
{
public:
    /*1. ���� ���
    * 2. ��ֹ���� ���Ϊ��
    * 3. ���㴦�� depth = max{getDepth[l], getDepth[r]} + 1
    */
    int getDepth(TreeNode* node)
    {
        if (node == nullptr) return 0;

        int lDepth = getDepth(node->left);
        int rDepth = getDepth(node->right);
        return 1 + max(lDepth, rDepth);
    }

    int maxDepth(TreeNode* root) 
    {
        return getDepth(root);
    }
};

// �ݹ鷨 ��
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

// ������
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;

        queue<TreeNode*> que;
        int depth = 1;
        que.push(root);
        que.push(nullptr);

        while (que.size() > 1)
        {
            TreeNode* cur = que.front();
            que.pop();

            if (cur)
            {
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            else
            {
                depth++;
                que.push(nullptr);
            }
        }

        return depth;
    }
};