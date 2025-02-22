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
    int give_num(const string& s, int& pos)
    {
        int ans = 0;

        string tmp;
        while (pos < s.size() && s[pos] != '-')
        {
            tmp += s[pos];
            pos++;
        }

        ans = stoi(tmp);

        return ans;
    }

    int count_D(const string& s, int& pos)
    {
        int ans = 0;

        while (pos < s.size() && s[pos] == '-')
        {
            ans++;
            pos++;
        }

        return ans;
    }

    void dfs(TreeNode* root, const string& s, int& pos, int lvl)
    {
        int c = count_D(s, pos);

        if (c == lvl)
        {
            TreeNode* tmp = new TreeNode(give_num(s, pos));
            root->left = tmp;

            dfs(root->left, s, pos, lvl + 1);    
        }
        else
        {
            pos -= c;
            return;
        }
        
        c = count_D(s, pos);
        if (c == lvl)
        {
            TreeNode* tmp = new TreeNode(give_num(s, pos));
            root->right = tmp;

            dfs(root->right, s, pos, lvl + 1);    
        }
        else
        {
            pos -= c;
            return;
        }
    }

public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        int pos = 0;
        
        TreeNode* root = new TreeNode(give_num(traversal, pos));

        dfs(root, traversal, pos, 1);

        return root;
    }
};