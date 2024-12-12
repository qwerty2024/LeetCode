class Solution 
{
public:
    int minMaxGame(vector<int>& nums) 
    {
        int n = nums.size();

        int count = n;
        while (count > 1)
        {
            count /= 2;
            for (int i = 0; i < count; i++)
            {
                if (i % 2 == 0)
                {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else
                {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
        }

        return nums[0];
    }
};