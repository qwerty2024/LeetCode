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
    int count = 0;
    int ans = 0;
    int _k = 0;

    void dfs(TreeNode* root)
    {
        if (count > _k)
            return;

        if (root->left)
            dfs(root->left);

        count++;
        if (count == _k)
            ans = root->val;

        if (root->right)
            dfs(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) 
    {
        _k = k;
        
        dfs(root);

        return ans;
    }
};