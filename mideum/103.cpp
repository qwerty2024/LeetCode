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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        int n = 1;

        while (!q.empty())
        {
            int count = 0;
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);

                if (node->left)
                {
                    count++;
                    q.push(node->left);
                }
                
                if (node->right)
                {
                    count++;
                    q.push(node->right);
                }
            }
            n = count;

            if (ans.size() & 1)
            {
                reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);
            }
            else
            {
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};