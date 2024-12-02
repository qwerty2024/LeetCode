class Solution 
{
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> m;

        for (auto a : arr)
            m[a]++;

        int maxi = -1;
        for (auto a : m)
        {
            if (a.second == a.first) 
            {
                maxi = max(maxi, a.first);
            }
        }

        return maxi;
    }
};