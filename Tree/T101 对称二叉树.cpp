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

// �ݹ�
class Solution 
{
public:
    /*
    * 1. ���� ������
    * 2. ��ֹ���� �����������һ��Ϊnull || ����������ֵ��һ��
    * 3. ���㴦�� �� [l-l, r-r] [l-r,r-l] ���жϲ���ȡ����ֵ ����ϱ����жϷ���
    */

    // �ݹ��ж� �������Ƿ�Գ�
    bool comp(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left->val != right->val) return false;
        // else left->val == right->val ��Ҫ������һ���ж�

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

// �ǵݹ�
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        // bd����Գ� �ȼ��� db����Գƣ�������Ⱥ�˳�򶼿��� 
        st.push(root->right);
        st.push(root->left);

        while (!st.empty())
        {
            TreeNode* left = st.top(); st.pop();
            TreeNode* right = st.top(); st.pop();

            if (left == nullptr && right == nullptr) continue;  // ����ע��
            else if (left == nullptr && right != nullptr) return false;
            else if (left != nullptr && right == nullptr) return false;
            else if (left->val != right->val) return false;
            // else left->val == right->val ��Ҫ������һ���ж�
            
            st.push(left->left);    st.push(right->right);
            st.push(left->right);   st.push(right->left);
        }

        return true;
    }
};