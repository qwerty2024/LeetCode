class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxi = nums[0];
        int current_sum = maxi;

        for (int i = 1; i < nums.size(); i++)
        {
            if (current_sum < 0)
            {
                maxi = max(maxi, nums[i]);
                current_sum = nums[i];
            }
            else
            {
                current_sum += nums[i];
                maxi = max(maxi, current_sum);
            }
        }

        return maxi;
    }
};