class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, 0));

        dp[0][nums[0] + 1000]++;
        dp[0][-nums[0] + 1000]++;

        for (int i = 1; i < n; i++) 
        {
            for (int sum = -1000; sum <= 1000; sum++) 
            {
                if (dp[i - 1][sum + 1000] > 0) 
                {
                    dp[i][sum + nums[i] + 1000] +=
                        dp[i - 1][sum + 1000];

                    dp[i][sum - nums[i] + 1000] +=
                        dp[i - 1][sum + 1000];
                }
            }
        }

        return abs(target) > 1000 ? 0 : dp[n - 1][target + 1000];
    }
};
/*
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int ans = 0;
        int n = nums.size();
        int maxi = pow(2, n);

        for (int i = 0; i < maxi; i++)
        {
            int id = i;
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (id & 1 == 1)
                {
                    sum += nums[j];
                }
                else
                {
                    sum -= nums[j];
                }

                id >>= 1;
            }

            if (sum == target)
                ans++;
        }

        return ans;
    }
};
*/