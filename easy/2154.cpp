class Solution 
{
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (original == nums[j])
                {
                    original *= 2;
                    break;
                }
            }
        }
        return original;
    }
};