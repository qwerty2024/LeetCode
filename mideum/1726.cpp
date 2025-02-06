class Solution 
{
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> um;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                um[nums[i] * nums[j]]++;
            }
        }

        for (auto a : um)
        {
            if (a.second >= 2)
            {
                ans += ((a.second * (a.second - 1)) / 2 ) * 8;
            }
        }

        return ans;
    }
};