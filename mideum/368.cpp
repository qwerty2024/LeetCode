class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> ans;

        vector<int> dp(n, 0);
        vector<int> dp2(n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        dp2[i] = j;
                    }
                }
            }
        }

        int max_ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > dp[max_ind])
                max_ind = i;
        }

        while (dp2[max_ind] != -1)
        {
            ans.push_back(nums[max_ind]);
            max_ind = dp2[max_ind];
        }

        ans.push_back(nums[max_ind]);

        return ans;
    }
};