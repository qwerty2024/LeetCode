class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        int m = grid.size();
        int ans = 0;
        int i = m - 1;
        
        for (int j = 0; j < n; j++)
        {
            while (i >= 0 && grid[i][j] < 0)
            {
                i--;
            }

            ans += m - i - 1;
        }

        return ans;
    }
};