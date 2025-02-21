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
class FindElements 
{
    unordered_set<int> data;

    void dfs(TreeNode* root, int v)
    {
        data.insert(v);

        if (root->left)
            dfs(root->left, 2 * v + 1);

        if (root->right)
            dfs(root->right, 2 * v + 2);
    }

public:
    FindElements(TreeNode* root) 
    {
        dfs(root, 0);    
    }
    
    bool find(int target) 
    {
        if (data.contains(target))
            return true;
        else
            return false;

        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */