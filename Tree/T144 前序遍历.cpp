#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 递归写法
class Solution 
{
public:
    /* 递归三要素
    * 1. 参数：当前结点 输出表
    * 2. 终止条件：当前结点为空
    * 3. 单层逻辑：前序
    */
    void traversal(vector<int>& vec, TreeNode* cur)
    {
        if (cur == nullptr)
        {
            return;
        }

        vec.push_back(cur->val);
        traversal(vec, cur->left);
        traversal(vec, cur->right);
    }


    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};

// 迭代写法
class Solution2
{
public:
        vector<int> preorderTraversal(TreeNode* root)
        {
            if (root == nullptr)
            {
                return vector<int>();
            }

            vector<int> result;
            stack<TreeNode*> st;

            //首先将当前结点压入栈
            st.push(root);

            while (!st.empty())
            {
                TreeNode* cur = st.top();
                st.pop();

                result.push_back(cur->val);

                // 压栈顺序与最终顺序相反
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            }

            return result;
        }
};

// 统一迭代写法
class Solution3
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return vector<int>();

        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            // 普通结点 访问
            if (cur != nullptr)
            {
                // 右
                if (cur->right) st.push(cur->right);
                // 左
                if (cur->left) st.push(cur->left);
                // 中
                st.push(cur);
                st.push(nullptr);
            }
            // 标记 处理
            else
            {
                cur = st.top();
                st.pop();

                result.push_back(cur->val);
            }
        }

        return result;
    }
};