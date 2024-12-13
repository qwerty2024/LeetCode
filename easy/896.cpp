class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n = nums.size();
        bool up = true;
        bool down = true;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1]) 
            {
                down = false;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1]) 
            {
                up = false;
            }
        }

        return up || down;
    }
};