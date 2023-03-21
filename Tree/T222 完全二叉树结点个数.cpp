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
    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;

        // �ܹ�ȷ����Ϊ����������
        int ldepth = 0, rdepth = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left)
        {
            ldepth++;
            left = left->left;
        }
        while (right)
        {
            rdepth++;
            right = right->right;
        }

        // ����������
        if (ldepth == rdepth)
        {
            return (2 << ldepth) - 1;
        }
        // ������������
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};