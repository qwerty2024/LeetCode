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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;

        if (!root)
            return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);
        int n = 1;

        while (!dq.empty())
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode* tmp = dq.front();
                dq.pop_front();

                if (i == 0)
                    ans.push_back(tmp->val);

                if (tmp->right)
                {
                    dq.push_back(tmp->right);
                    count++;
                }

                if (tmp->left)
                {
                    dq.push_back(tmp->left);
                    count++;
                }
            }
            n = count;
        }
        
        return ans;
    }
};