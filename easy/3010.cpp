class Solution 
{
public:
    int minimumCost(vector<int>& nums) 
    {
        int ans = nums[0];

        auto first = min_element(nums.begin() + 1, nums.end());
        ans += *first;
        *first = 55;
        auto second = min_element(nums.begin() + 1, nums.end());
        ans += *second;
        
        return ans;
    }
};