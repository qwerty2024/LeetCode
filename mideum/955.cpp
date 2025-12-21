class Solution 
{
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        
        vector<int> check(m, 0);

        for (int i = 0; i < n; i++)
        {
            bool del = false;

            for (int j = 0; j < m - 1; j++)
            {
                if (check[j] == check[j + 1] && strs[j][i] > strs[j + 1][i])
                {
                    del = true;
                    ans++;
                    break;
                }
            }

            if (del)
                continue;
            
            vector<int> tmp(m, 0);
            int group = 1;

            for (int j = 0; j < m - 1; j++)
            {
                if (check[j] == check[j + 1] && strs[j][i] == strs[j + 1][i])
                {
                    tmp[j] = group;
                    tmp[j + 1] = group;
                }
                else
                {
                    tmp[j] = group;
                    tmp[j + 1] = ++group;
                }
            }

            check = tmp;
        }

        return ans;
    }
};