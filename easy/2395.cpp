class Solution 
{
public:
    bool findSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[i - 1] == nums[j] + nums[j - 1])
                    return true;
            }
        }

        return false;
    }
};