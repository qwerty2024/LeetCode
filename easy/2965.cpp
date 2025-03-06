class Solution 
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        unordered_map<int, int> m;
        for (auto a : grid)
            for (auto b : a)
                m[b]++;
        
        vector<int> ans(2);
        for (int i = 1; i <= grid.size() * grid.size(); i++)
        {
            if (!m.contains(i)) ans[1] = i;
            if (m[i] == 2) ans[0] = i;
        }
        return ans;
    }
};