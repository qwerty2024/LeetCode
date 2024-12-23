class Solution 
{
    int minSwapsToSort(vector<int>& arr) 
    {
        int n = arr.size();
        vector<pair<int, int>> arrPos(n);
    
        for (int i = 0; i < n; i++) 
        {
            arrPos[i] = {arr[i], i};
        }

        sort(arrPos.begin(), arrPos.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) 
        {
            if (visited[i] || arrPos[i].second == i) 
            {
                continue;
            }

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) 
            {
                visited[j] = true;
                j = arrPos[j].second;
                cycle_size++;
            }

            if (cycle_size > 0) 
            {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }

public:
    int minimumOperations(TreeNode* root) 
    {
        deque<TreeNode*> dq;
        dq.push_back(root);
        int n = 1;
        int ans = 0;

        while (!dq.empty())
        {
            int count = 0;
            vector<int> next;

            for (int i = 0; i < n; i++)
            {
                TreeNode* tmp = dq.front();
                dq.pop_front();

                if (tmp->left)
                {
                    dq.push_back(tmp->left);
                    next.push_back(tmp->left->val);
                    count++;
                }

                if (tmp->right)
                {
                    dq.push_back(tmp->right);
                    next.push_back(tmp->right->val);
                    count++;
                }
            }

            //for (int i = 0; i < next.size(); i++)
            //{
            //    cout << next[i] << " ";
            //}
            //cout << endl;
            ans += minSwapsToSort(next);

            n = count;
        }

        return ans;
    }
};