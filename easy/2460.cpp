class Solution 
{
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
                i++;
            }
        }

        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            while (i < nums.size() && nums[i] != 0)
            {
                i++;
                j++;
            }

            while (j < nums.size() && nums[j] == 0)
            {
                j++;
            }

            if (j < nums.size() && i < nums.size()) swap(nums[i], nums[j]);

            j++;
            i++;
        }

        return nums;
    }
};