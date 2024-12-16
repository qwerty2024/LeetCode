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
    vector<int> ans;
    int curr_len = 0;
    int max_len = 0;
    int val = INT_MIN;

    void dfs(TreeNode* root)
    {
        if (!root) return;

        dfs(root->left);

        if (val == root->val)
        {
            curr_len++;
        }
        else
        {
            val = root->val;
            curr_len = 1;
        }


        if (curr_len == max_len)
        {
            ans.push_back(root->val);
        }
        else if (curr_len > max_len)
        {
            max_len = curr_len;
            ans.clear();
            ans.push_back(root->val);
        }
        

        dfs(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) 
    {
        dfs(root);
        return ans;
    }
};