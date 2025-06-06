class Solution 
{
    int n;
    void backtr(vector<vector<int>>& ans, vector<int>& nums, int depth)
    {
        if (depth == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = depth; i < n; i++)
        {
            swap(nums[depth], nums[i]);

            backtr(ans, nums, depth + 1);

            swap(nums[depth], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n = nums.size();
        vector<vector<int>> ans;

        backtr(ans, nums, 0);

        return ans;
    }
};