class Solution 
{
public:
    bool divideArray(vector<int>& nums) 
    {
        map<int, int> m;

        for (auto a : nums)
        {
            m[a]++; 
        }
        
        for (auto a : m)
            if (a.second % 2 == 1) return false;

        return true;
    }
};