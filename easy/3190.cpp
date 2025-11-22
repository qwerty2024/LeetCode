class Solution 
{
public:
    int minimumOperations(vector<int>& nums) 
    {
        int ans = 0;
        for (auto a : nums)
            if (a % 3 != 0)
                ans++;
        
        return ans;
    }
};