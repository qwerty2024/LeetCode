class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        set<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int k = 0; k < n - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;

            int l = k + 1;
            int r = n - 1;

            while (l < r)
            {
                if (nums[k] + nums[l] + nums[r] == 0)
                    ans.insert({nums[k], nums[l], nums[r]});

                if (nums[l] + nums[r] > (0 - nums[k]))
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        return {ans.begin(), ans.end()};
    }
};