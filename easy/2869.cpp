class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_set<int> us;

        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] <= k)
            {
                us.insert(nums[i]);
            }
            ans++;

            if (us.size() == k) return ans;
        }

        return ans;
    }
};