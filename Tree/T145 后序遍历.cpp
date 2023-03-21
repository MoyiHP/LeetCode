#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return vector<int>();
        }

        vector<int> result;
        stack<TreeNode*> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            result.push_back(cur->val);

            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};