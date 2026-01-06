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
public:
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        int n = 1;
        int maxi = root->val;
        int current_lvl = 1;
        int ans = 1;
        q.push(root);

        while (!q.empty())
        {
            bool flag = false;
            int p = 0;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left)
                {
                    flag = true;
                    sum += tmp->left->val;
                    q.push(tmp->left);
                    p++;
                }

                if (tmp->right)
                {
                    flag = true;
                    sum += tmp->right->val;
                    q.push(tmp->right);
                    p++;
                }
            }
            current_lvl++;

            if (flag && sum > maxi)
            {
                maxi = sum;
                ans = current_lvl;
            }

            n = p;
        }

        return ans;
    }
};