class Solution 
{
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int res = abs(nums[0]);
        int maxEnding = nums[0];

        for (int i = 1; i < nums.size(); i++) 
        {
            maxEnding = max(maxEnding + nums[i], nums[i]);

            res = max(res, abs(maxEnding));
        }

        maxEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) 
        {
            maxEnding = min(maxEnding + nums[i], nums[i]);

            res = max(res, abs(maxEnding));
        }

        return res;
    }
};