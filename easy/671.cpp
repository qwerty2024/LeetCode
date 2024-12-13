class Solution 
{
    int dfs(TreeNode* root, int num)
    {
        if (root->left)
        {
            int l = dfs(root->left, num);
            int r = dfs(root->right, num);
            if (l == num) return r;
            if (r == num) return l;

            return min(l, r);
        }

        return root->val;
    }

public:
    int findSecondMinimumValue(TreeNode* root) 
    {
        int res = dfs(root, root->val);
        return (root->val == res) ? -1 : res;
    }
};