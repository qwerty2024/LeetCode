/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    stack<TreeNode*> st_p;
    stack<TreeNode*> st_q;
    TreeNode* _p;
    TreeNode* _q;

    void dfs(TreeNode* root, stack<TreeNode*>& st_curr)
    {
        st_curr.push(root);

        if (root == _p)
        {
            st_p = st_curr;
        }
        
        if (root == _q)
        {
            st_q = st_curr;
        }

        if (root->left)
            dfs(root->left, st_curr);

        if (root->right)
            dfs(root->right, st_curr);

        st_curr.pop();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        _p = p;
        _q = q;

        stack<TreeNode*> st;

        dfs(root, st);

        while (true)
        {
            if (st_p.top() == st_q.top())
            {
                return st_p.top();
            }
            else if (st_p.size() > st_q.size())
            {
                st_p.pop();
            }
            else
            {
                st_q.pop();
            }
        }

        return nullptr;
    }
};