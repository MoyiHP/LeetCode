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

// �ݹ�д��
class Solution 
{
public:
    /* �ݹ���Ҫ��
    * 1. ��������ǰ��� �����
    * 2. ��ֹ��������ǰ���Ϊ��
    * 3. �����߼���ǰ��
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

// ����д��
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

            //���Ƚ���ǰ���ѹ��ջ
            st.push(root);

            while (!st.empty())
            {
                TreeNode* cur = st.top();
                st.pop();

                result.push_back(cur->val);

                // ѹջ˳��������˳���෴
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            }

            return result;
        }
};

// ͳһ����д��
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

            // ��ͨ��� ����
            if (cur != nullptr)
            {
                // ��
                if (cur->right) st.push(cur->right);
                // ��
                if (cur->left) st.push(cur->left);
                // ��
                st.push(cur);
                st.push(nullptr);
            }
            // ��� ����
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