class Solution 
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) 
    {
        map<int, int> tmp;

        for (auto a : n1)
            tmp[a[0]] += a[1];

        for (auto a : n2)
            tmp[a[0]] += a[1];

        vector<vector<int>> ans;

        for (auto a : tmp)
            ans.push_back(vector<int>{a.first, a.second});

        return ans;
    }
};