class Solution 
{
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        int n = nums.size();

        for (int k = 0; k < n / 2; k++)
        {
            for (int i = 2; i < n; i += 2)
            {
                if (nums[i - 2] > nums[i]) swap(nums[i - 2], nums[i]);
            }

            for (int i = 3; i < n; i += 2)
            {
                if (nums[i - 2] < nums[i]) swap(nums[i - 2], nums[i]);
            }
        }

        return nums;
    }
};