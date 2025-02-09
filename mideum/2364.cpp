class Solution 
{
public:
    long long countBadPairs(vector<int>& nums) 
    {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            if (um.contains(nums[i] - i))
            {
                ans += um[nums[i] - i];
            }

            um[nums[i] - i]++;
        }

        long long tmp = (((long long)n * ((long long)n - 1)) / 2);

        return tmp - ans;
    }
};