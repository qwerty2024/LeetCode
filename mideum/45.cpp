class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);

        int right = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + nums[i] > right)
            {
                for (int j = right + 1; j < n && j <= i + nums[i]; j++)
                    dp[j] = dp[i] + 1;

                right = i + nums[i];
            }
        }

        return dp[n - 1];
    }
};