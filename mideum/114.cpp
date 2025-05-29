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
    TreeNode* dfs(TreeNode* root)
    {
        if (root->left)
        {
            TreeNode* saved = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* last = dfs(root->right);
            last->right = saved;

            if (saved)
            {
                return dfs(saved);
            }

            return last;
        }
        else if (root->right)
        {
            return dfs(root->right);
        }
        else
            return root;
    }

public:
    void flatten(TreeNode* root) 
    {
        if (!root)
            return;

        dfs(root);
    }
};