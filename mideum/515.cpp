class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> qu;
        qu.push(root);
        int n = 1;
        ans.push_back(root->val);

        while (!qu.empty())
        {
            int count = 0;
            int maxi = INT_MIN;
            int flag = false;

            for (int i = 0; i < n; i++)
            {
                auto tmp = qu.front();
                qu.pop();

                if (tmp->left)
                {
                    flag = true;
                    qu.push(tmp->left);
                    count++;
                    maxi = max(maxi, tmp->left->val);
                }

                if (tmp->right)
                {
                    flag = true;
                    qu.push(tmp->right);
                    count++;
                    maxi = max(maxi, tmp->right->val);
                }
            }

            if (flag) ans.push_back(maxi);
            n = count;
        }

        return ans;
    }
};