class Solution 
{
public:
    int maxSum(vector<int>& nums) 
    {
        unordered_set<int> us;

        int maxi = -1111;

        for (const auto& a : nums)
        {
            maxi = max(maxi, a); 
            us.insert(a);
        }

        if (maxi <= 0)
            return maxi;

        int res = 0;

        for (const auto& a : us)
        {
            if (a > 0)
                res += a;
        }

        return res;
    }
};