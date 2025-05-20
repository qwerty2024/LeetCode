class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 666666;

        int l = 0;
        int r = 0;
        int curr_sum = nums[0];

        while (true)
        {
            while (r < (n - 1) && curr_sum < target)
            {
                r++;
                curr_sum += nums[r];
            }

            while (l < n && curr_sum - nums[l] >= target)
            {
                curr_sum -= nums[l];
                l++;
            }

            if (curr_sum >= target)
                ans = min(ans, r - l + 1);

            r++;

            if (r == n)
                break;

            curr_sum += nums[r];
        }

        return ans == 666666 ? 0 : ans;
    }
};