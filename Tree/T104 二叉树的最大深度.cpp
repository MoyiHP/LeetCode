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

// 递归法
class Solution 
{
public:
    /*1. 参数 结点
    * 2. 终止条件 结点为空
    * 3. 本层处理 depth = max{getDepth[l], getDepth[r]} + 1
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

// 递归法 简化
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

// 迭代法
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