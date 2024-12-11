class Solution 
{
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) 
    {
        vector<int> ans;
        vector<int> seen;

        int count = 0;
        for (auto a : nums)
        {
            if (a == -1)
            {
                count++;
                if (seen.size() < count)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(seen[seen.size() - count]);
                }
            }
            else
            {
                seen.push_back(a);
                count = 0;
            }
        }

        return ans;
    }
};