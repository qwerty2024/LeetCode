class Solution 
{
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans[i] = nums[i];
            }
            else if (nums[i] > 0)
            {
                ans[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] < 0)
            {
                int j = (abs(nums[i]) % n) * (-1);
                if (i + j < 0)
                {
                    ans[i] = nums[n + i + j];
                }
                else
                    ans[i] = nums[i + j];
            }
        }


        return ans;
    }
};