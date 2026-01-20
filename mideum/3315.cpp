class Solution 
{
    int fnk(int n)
    {
        if (n == 2)
            return -1;

        int item = 1;
        int save = n;
        n >>= 1;

        while (n > 0)
        {
            if (n % 2 == 0)
            {
                return save ^ item;
            }
            item <<= 1;
            n >>= 1;
        }

        return save ^ item;
    }

public:
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        vector<int> ans;

        for (const auto& a : nums)
        {
            ans.push_back(fnk(a));
        }

        return ans;
    }
};