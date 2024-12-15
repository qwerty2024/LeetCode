class Solution 
{
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) 
    {
        pair<int, int> ans = {0, divisors[0]};
        for (int a : divisors)
        {
            int count = 0;
            for (auto b : nums)
            {
                if (b % a == 0)
                {
                    count++;
                }
            }

            if (count == ans.first)
            {
                ans.second = min(a, ans.second);
            }
            else if (count > ans.first)
            {
                ans = {count, a};
            }
        }

        return ans.second;
    }
};