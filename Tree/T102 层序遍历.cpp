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

// 递归方法
class Solution 
{
public:
    /* 递归三要素
    * 1. 参数：记录数组 当前结点 当前深度
    * 2. 终止条件：访问到空结点
    * 3. 单层逻辑：访问当前结点，将值添加到记录数组，递归访问下层结点，深度加一
    */
    void traversal(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        // 终止条件
        if (cur == nullptr) return;

        // 本层处理
        if (result.size() == depth) result.emplace_back(vector<int>()); // 当访问到每层的最左侧结点时 需要扩充记录数组
        result[depth].push_back(cur->val);

        // 递归逻辑
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

// 迭代方法
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr) return vector<vector<int>>();
        
        vector<vector<int>> result;
        queue<TreeNode*> que;
        
        // 当前层数
        int depth = 0;
        result.emplace_back(vector<int>());
        que.push(root);
        // 使用nullptr作为每层结束的标记 其每次被弹出后 将再次入队
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