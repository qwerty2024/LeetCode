class Solution 
{
    bool test(vector<int>& nums, int i, int j)
    {
        int last = -1;
        for (int k = 0; k < nums.size(); k++)
        {
            if (k >= i && k <= j)
                continue;

            if (last == -1) 
            {
                last = nums[k];
                continue;
            }

            if (last >= nums[k])
                return false;

            last = nums[k];
        }

        return true;
    }

public:
    int incremovableSubarrayCount(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (test(nums, i, j))
                    ans++;
            }
        }

        return ans;
    }
};