class Solution 
{
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        vector<long long> suff(n + 1, 0);
        
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        for (int i = n - 1; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i];

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            if (pref[i + 1] >= suff[i + 1])
                ans++;

        return ans;
    }
};