class Solution 
{
public:
    int findLHS(vector<int>& nums) 
    {
        unordered_map<int, int> um;

        for (auto a : nums)
            um[a]++;

        int maxi = 0;

        for (auto a : um)
        {
            if (um.contains(a.first - 1))
            {
                maxi = max(maxi, a.second + um[a.first - 1]);
            }
            if (um.contains(a.first + 1))
            {
                maxi = max(maxi, a.second + um[a.first + 1]);
            }
        }

        return maxi;
    }
};