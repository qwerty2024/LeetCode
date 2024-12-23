class Solution 
{
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        unordered_map<int, int> um;

        for (auto a : nums)
        {
            if (a % 2 == 0) um[a]++;
        } 

        int maxi_count = -1;
        int min_el = INT_MAX;

        for (auto a : um)
        {
            if (maxi_count == a.second)
            {
                if (min_el > a.first)
                {
                    min_el = a.first;
                    maxi_count = a.second;
                }
            }
            else if (maxi_count < a.second)
            {
                min_el = a.first;
                maxi_count = a.second;
            }
        }

        return min_el == INT_MAX ? -1 : min_el;
    }
};