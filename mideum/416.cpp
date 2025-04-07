class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();

        int sum = reduce(nums.begin(), nums.end());

        if (sum % 2 == 1)
            return false;

        sum /= 2;

        vector<bool> dp(20001, false);

        dp[nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            vector<bool> tmp = dp;

            for (int j = 0; j < 20001; j++)
            {
                if (dp[j])
                {
                    tmp[j + nums[i]] = true;
                }
            }

            dp = tmp;
        }

        return dp[sum];
    }
};