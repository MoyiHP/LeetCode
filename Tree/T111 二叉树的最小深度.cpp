#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    /*1. 参数 当前结点
    * 2. 终止条件 当前结点为叶结点（为了避免空结点导致错误）
    * 3. 本层 计算
    */
    int getDepth(TreeNode* node)
    {
        assert(node);
        if (node->left == nullptr && node->right == nullptr)
        {
            return 1;
        }

        int l = INT_MAX, r = INT_MAX;
        if (node->left) l = getDepth(node->left);
        if (node->right) r = getDepth(node->right);
        return 1 + min(l, r);
    }


    int minDepth(TreeNode* root) 
    {
        if (root)
        {
            return getDepth(root);
        }
        else
        {
            return 0;
        }
    }
};