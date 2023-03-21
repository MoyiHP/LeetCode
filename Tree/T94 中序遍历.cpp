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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return vector<int>();
        
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            if (cur != nullptr)
            {
                // ÓÒ
                if (cur->right) st.push(cur->right);
                // ÖÐ
                st.push(cur);
                st.push(nullptr);
                // ×ó
                if (cur->left) st.push(cur->left);
            }
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