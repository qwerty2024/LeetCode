class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<long long> pref(k, LLONG_MAX);
        pref[0] = 0;
        
        long long sum = 0;
        long long res = LLONG_MIN;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            int z = (i + 1) % k;

            if (pref[z] < LLONG_MAX) 
                res = max(res, sum - pref[z]);
            
            pref[z] = min(pref[z], sum);
        }

        return res;
    }
};
