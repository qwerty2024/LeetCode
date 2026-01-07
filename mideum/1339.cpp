
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
    long long maxi;
    int all = 0;

    void dfs_val(TreeNode* root)
    {
        if (root->left)
        {
            dfs_val(root->left);
            root->val += root->left->val;
        }

        if (root->right)
        {
            dfs_val(root->right);
            root->val += root->right->val;
        }
    }

    void dfs(TreeNode* root)
    {
        //cout << (parent_val - root->val) << " * " << root->val << "\n";
        if ((long long)(all - root->val) * root->val > maxi)
        {
            maxi = (long long)(all - root->val) * root->val;
        }

        if (root->left)
        {
            dfs(root->left);
        }

        if (root->right)
        {
            dfs(root->right);
        }
    }

public:
    int maxProduct(TreeNode* root) 
    {
        dfs_val(root);

        all = root->val;
        dfs(root);

        return (int)(maxi % 1000000007);
    }
};