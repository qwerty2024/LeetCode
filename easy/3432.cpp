class Solution 
{
public:
    int countPartitions(vector<int>& nums) 
    {
        int n = nums.size();

        int sum = 0;
        for (auto& a : nums)
            sum += a;
        
        int ans = 0;
        int curr = nums[0];
        for (int i = 1; i < n; i++)
        {
            if ((curr - (sum - curr)) % 2 == 0)
                ans++;

            curr += nums[i];
        }

        return ans;
    }
};