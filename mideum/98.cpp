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
    vector<int> tmp;

    void dfs(TreeNode* root)
    {
        if (root->left)
            dfs(root->left);

        tmp.push_back(root->val);

        if (root->right)
            dfs(root->right);
    }

public:
    bool isValidBST(TreeNode* root) 
    {
        dfs(root);

        if (tmp.size() == 1)
            return true;
        
        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] <= tmp[i - 1])   
                return false;
        }

        return true;
    }
};