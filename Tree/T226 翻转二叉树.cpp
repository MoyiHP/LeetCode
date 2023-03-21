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

class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == nullptr) return root;

        // ”√«∞–Ú±È¿˙
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            swap(cur->left, cur->right);

            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }

        return root;
    }
};