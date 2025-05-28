/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    unordered_map<int, int> pos;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& ind, int left_l, int right_l, int left_r, int right_r)
    {
        TreeNode* left_node = nullptr;
        TreeNode* right_node = nullptr;

        int val = preorder[ind];

        if (left_l == right_l)
        {
            ind++;
            left_node = new TreeNode(inorder[left_l]);
        }
        else if (left_l < right_l)
        {
            ind++;
            left_node = dfs(preorder, inorder, ind, left_l, pos[preorder[ind]] - 1, pos[preorder[ind]] + 1, right_l);
        }

        if (left_r == right_r)
        {
            ind++;
            right_node = new TreeNode(inorder[left_r]);
        }
        else if (left_r < right_r)
        {
            ind++;
            right_node = dfs(preorder, inorder, ind, left_r, pos[preorder[ind]] - 1, pos[preorder[ind]] + 1, right_r);
        }

        TreeNode* new_node = new TreeNode(val, left_node, right_node);

        return new_node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            pos[inorder[i]] = i;
        }

        int ind = 0;

        return dfs(preorder, inorder, ind, 0, pos[preorder[ind]] - 1, pos[preorder[ind]] + 1, preorder.size() - 1);
    }
};