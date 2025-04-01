class Solution
{
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        int n = questions.size();
        vector<long long> dp(n, 0);

        if (questions[0][1] + 1 < n)
            dp[questions[0][1] + 1] = questions[0][0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1]);

            if (i + questions[i][1] + 1 < n)
                dp[i + questions[i][1] + 1] = max(dp[i] + questions[i][0], dp[i + questions[i][1] + 1]);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            //cout << dp[i] << " ";
            ans = max(ans, dp[i] + questions[i][0]);
        }

        return ans;
    }
};