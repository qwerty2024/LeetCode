class Solution 
{
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long ans = 0;

        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = max(nums[i], pref[i - 1]);
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = max(nums[i], suff[i + 1]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, (long long)(pref[i - 1] - nums[i]) * suff[i + 1]);
        }

        return ans;
    }
};