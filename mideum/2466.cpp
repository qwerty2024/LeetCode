class Solution 
{
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        const int mod = 1000000007;
        int ans = 0;

        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            long long curr = 0;
            if (i - zero >= 0) curr += dp[i - zero];
            if (i - one >= 0) curr += dp[i - one];
            curr %= mod;
            dp[i] = curr;
        }

        for (int i = low; i <= high; i++)
        {
            ans += dp[i];
            ans %= mod;
        }

        return ans;
    }
};