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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        int lvl = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int n = 1;
        vector<int> v;
        
        while (!qu.empty())
        {
            v.resize(pow(2, (lvl + 1)));

            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (lvl % 2 == 1)
                {
                    qu.front()->val = v[n - i - 1];
                }
                
                if (qu.front()->left)
                {
                    qu.push(qu.front()->left);
                    qu.push(qu.front()->right);

                    if (lvl % 2 == 0)
                    {
                        v[count++] = qu.front()->left->val;
                        v[count++] = qu.front()->right->val;
                    }
                    else
                        count += 2;
                }
                qu.pop();
            }

            lvl++;
            n = count;
        }

        return root;
    }
};