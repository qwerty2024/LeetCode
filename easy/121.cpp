class Solution 
{
public:
    int maxProfit(vector<int>& p) 
    {
        int n = p.size();
        vector<int> dp(n, 0);
        dp[0] = p[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[i - 1], p[i]);
        }

        int maxi = -1;

        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, p[i] - dp[i]);
        }


        return maxi < 1 ? 0 : maxi;
    }
};