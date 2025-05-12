class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();

        int i = 0;
        int right = nums[0];
        while (i < n && i <= right)
        {
            right = max(right, i + nums[i]);

            if (right >= n - 1)
                return true;

            i++;
        }

        return false;
    }
};