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
    long long ans = 0;

    void dfs(TreeNode* root, long long& ans, int num)
    {
        if (!root)
            return;

        num += root->val;

        if (!(root->left) && !(root->right))
        {
            ans += num;
            return;
        }

        if (root->left)
        {
            dfs(root->left, ans, num * 10);
        }

        if (root->right)
        {
            dfs(root->right, ans, num * 10);
        }
    }

public:
    int sumNumbers(TreeNode* root) 
    {
        dfs(root, ans, 0);

        return ans;
    }
};