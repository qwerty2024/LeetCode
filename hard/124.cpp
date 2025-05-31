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
    int maxi = INT_MIN;

    int dfs(TreeNode* root)
    {
        if (!(root->left) && !(root->right))
        {
            maxi = max(maxi, root->val);
            return root->val;
        }

        int l = 0;
        int r = 0;

        if (root->left)
        {
            l = dfs(root->left);
        }

        if (root->right)
        {
            r = dfs(root->right);
        }

        maxi = max(maxi, l + r + root->val);

        int local_maxi = max(max(root->val + l, root->val + r), root->val);

        maxi = max(maxi, local_maxi);

        return local_maxi;
    }

public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxi;
    }
};