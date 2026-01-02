class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_set<int> us;

        for (const auto& a : nums)
        {
            if (us.contains(a))
                return a;
            else
                us.insert(a);
        }

        return 0;
    }
};