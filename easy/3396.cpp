class Solution 
{
    bool test(const unordered_map<int, int>& um)
    {
        for (auto a : um)
            if (a.second > 1)
                return false;
        return true;
    }
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> um;
        for (auto a : nums)
            um[a]++;

        int ans = 0;
        for (int i = 0; i < n; i)
        {
            if (!test(um))
            {
                if (i < n) um[nums[i++]]--;
                if (i < n) um[nums[i++]]--;
                if (i < n) um[nums[i++]]--;
                ans++;
            }
            else return ans;
        }  

        
        
        return ans;
    }
};