class Solution 
{
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) 
    {
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> pref(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            pref[i] = pref[i - 1] + nums[i - 1];
        }

        for (int i = l; i <= r; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                int sum = pref[j + i] - pref[j];
                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};