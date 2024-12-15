class Solution
{
public:
    int dominantIndex(vector<int>& nums)
    {
        auto ind = max_element(nums.begin(), nums.end());
        int maxi = *ind;

        for (auto a : nums)
        {
            if (a != maxi)
            {
                if (2 * a > maxi)
                    return -1;
            }
        }

        return (ind - nums.begin()) ;
    }
};