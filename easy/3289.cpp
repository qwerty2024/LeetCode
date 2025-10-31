class Solution 
{
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        vector<int> ans;

        for (auto& a : nums)
            a++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) + 1] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
                nums[abs(nums[i]) + 1] = -(nums[abs(nums[i]) + 1]);
        }

        ans[0]--;
        ans[1]--;
        return ans;
    }
};