class Solution 
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(n - i, 0);

            for (int j = i; j < n; j++)
            {
                tmp[j - i] = grid[j][j - i];
            }

            sort(tmp.begin(), tmp.end(), greater());

            for (int j = i; j < n; j++)
            {
                ans[j][j - i] = tmp[j - i];
            }
        }

        for (int i = 1; i < n; i++)
        {
            vector<int> tmp(n - i, 0);

            for (int j = i; j < n; j++)
            {
                tmp[j - i] = grid[j - i][j];
            }

            sort(tmp.begin(), tmp.end());

            for (int j = i; j < n; j++)
            {
                ans[j - i][j] = tmp[j - i];
            }
        }
        
        return ans;
    }
};