class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = nums[0];
        int maxEnd = nums[0];       
        int mini = nums[0];
        int minEnd = nums[0];

        for (int i = 1; i < n; i++)
        {
            maxEnd = max(nums[i], maxEnd + nums[i]);
            maxi = max(maxi, maxEnd);
        }

        for (int i = 1; i < n; i++)
        {
            minEnd = min(nums[i], minEnd + nums[i]);
            mini = min(mini, minEnd);
        }

        if (maxi < 0)
            return maxi;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        return max(maxi, sum - mini);
    }
};