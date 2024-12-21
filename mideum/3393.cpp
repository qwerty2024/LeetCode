class Solution
{
    int MOD = 1000000007;
    int n = 0;
    int m = 0;

public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k)
    {
        m = grid[0].size();
        n = grid.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16, 0)));

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (i == 0 && j == 0)
                    dp[i][j][grid[i][j]]++;
                else
                {
                    if (i > 0)
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if(dp[i - 1][j][k] > 0)
                            {
                                dp[i][j][k ^ grid[i][j]] += dp[i - 1][j][k];
                                dp[i][j][k ^ grid[i][j]] %= MOD;
                            }
                        }
                    }

                    if (j > 0)
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if(dp[i][j - 1][k] > 0)
                            {
                                dp[i][j][k ^ grid[i][j]] += dp[i][j - 1][k];
                                dp[i][j][k ^ grid[i][j]] %= MOD;
                            }
                        }
                    }
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};