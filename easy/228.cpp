class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n = nums.size();
        vector<string> ans;

        for (int i = 0; i < n; i++)
        {
            int current = i;
            while ((i + 1) < n && nums[i] + 1 == nums[i + 1])
            {
                i++;
            }

            if (current == i)
            {
                ans.push_back(to_string(nums[i]));
            }
            else
            {
                ans.push_back(to_string(nums[current]) + "->" + to_string(nums[i]));
            }
        }

        return ans;
    }
};