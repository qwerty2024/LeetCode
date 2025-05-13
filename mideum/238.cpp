class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> pref(n + 1, 1);
        vector<int> suff(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] * nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = suff[i + 1] * nums[i];
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            ans[i] = pref[i] * suff[i + 1];
        }

        return ans;
    }
};