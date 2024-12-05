class Solution 
{
public:
    int arraySign(vector<int>& nums) 
    {
        int ans = 1;
        for (auto a : nums)
        {
            if (a == 0)
            {
                return 0;
            }
            else if (a < 0)
            {
                ans *= -1;
            }
        }

        return ans;
    }
};
