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

// 递归
class Solution 
{
public:
    /*
    * 1. 参数 两个树
    * 2. 终止条件 两个根结点有一个为null || 两个根结点的值不一致
    * 3. 本层处理 对 [l-l, r-r] [l-r,r-l] 做判断并获取返回值 ，结合本层判断返回
    */

    // 递归判断 两个树是否对称
    bool comp(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left->val != right->val) return false;
        // else left->val == right->val 需要后续进一步判断

        bool ll_rr = comp(left->left, right->right);
        if (ll_rr == false) return false;

        bool lr_rl = comp(left->right, right->left);
        if (lr_rl == false) return false;

        return true;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return comp(root->left, root->right);
        }
    }
};

// 非递归
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        // bd镜像对称 等价与 db镜像对称，这里的先后顺序都可以 
        st.push(root->right);
        st.push(root->left);

        while (!st.empty())
        {
            TreeNode* left = st.top(); st.pop();
            TreeNode* right = st.top(); st.pop();

            if (left == nullptr && right == nullptr) continue;  // 这里注意
            else if (left == nullptr && right != nullptr) return false;
            else if (left != nullptr && right == nullptr) return false;
            else if (left->val != right->val) return false;
            // else left->val == right->val 需要后续进一步判断
            
            st.push(left->left);    st.push(right->right);
            st.push(left->right);   st.push(right->left);
        }

        return true;
    }
};