class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();

        if (n == 1) return true;
    
        int idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                idx = i;
                break;
            }
        }

        if (idx == 0) return true;

        for (int i = idx + 1; i < n + idx; i++)
        {
            if (nums[i % n] < nums[(i - 1) % n])
                return false;
        }

        return true;
    }
};