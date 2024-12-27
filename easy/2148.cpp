class Solution 
{
public:
    int countElements(vector<int>& nums) 
    {
        int ans = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        unordered_map<int, int> um;

        for (auto a : nums)
            um[a]++;

        for (auto a : um)
            if (a.first != maxi && a.first != mini) ans += a.second;

        return ans;
    }
};