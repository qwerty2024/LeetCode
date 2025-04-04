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
    TreeNode* ans = nullptr;
    int max_depth = -1;
    vector<int> par;
    vector<int> dpths;

    void dfs(TreeNode* root, int lvl)
    {
        max_depth = max(max_depth, lvl);
        dpths[root->val] = lvl;

        if (root->left) 
        {
            par[root->left->val] = root->val;
            dfs(root->left, lvl + 1);
        }

        if (root->right) 
        {
            par[root->right->val] = root->val;
            dfs(root->right, lvl + 1);
        }
    }

    void search(TreeNode* root, int value)
    {
        if (root->val == value)
            ans = root;

        if (root->left) 
        {
            search(root->left, value);
        }

        if (root->right) 
        {
            search(root->right, value);
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        par.resize(1001, -1);
        dpths.resize(1001, -1);

        dfs(root, 0);

        int curr = -1;
        int i = 0;

        while (1)
        {
            if (max_depth == dpths[i])
            {
                curr = i;
                break;
            }

            i++;
        }

        for (i = curr + 1; i < 1001; i++)
        {
            if (max_depth == dpths[i])
            {
                // lca(curr, i);
                int u = i;
                int v = curr;
                int h1 = dpths[i];
                int h2 = dpths[curr];

                while (h1 != h2)
                {
                    if (h1 > h2)
                    {
                        u = par[u];
                        h1--;
                    }
                    else
                    {
                        v = par[v];
                        h2--;
                    }
                }

                while (u != v)
                {
                    u = par[u];  
                    v = par[v];
                }

                curr = u;
            }
        }
        
        search(root, curr);

        return ans;
    }
};
