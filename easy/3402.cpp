class Solution 
{
public:
    int minimumOperations(vector<vector<int>>& g) 
    {
        int m = g.size();
        int n = g[0].size();
        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < m; i++)
            {
                if (g[i][j] <= g[i - 1][j])
                {
                    ans += g[i - 1][j] - g[i][j] + 1;
                    g[i][j] += g[i - 1][j] - g[i][j] + 1;
                }    
            }    
        }
        
        return ans;
    }
};