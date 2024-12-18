class Solution 
{
public:
    bool isGood(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> v(maxi, 0);

        for (auto a : nums)
        {
            v[a - 1]++;
        }

        for (int i = 0; i < maxi - 1; i++)
        {
            if (v[i] != 1) 
                return false;
        }

        if (v[maxi - 1] != 2)
            return false;

        return true;
    }
};