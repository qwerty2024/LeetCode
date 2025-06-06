class Solution 
{
    int _n;
    int _k;

    void backtr(vector<vector<int>>& ans, int count, vector<int>& curr)
    {
        if (curr.size() == _k)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = count; i <= _n; i++)
        {
            curr.push_back(i);

            backtr(ans, i + 1, curr);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) 
    {
        _k = k;
        _n = n;
        vector<vector<int>> ans;

        vector<int> curr{};
        backtr(ans, 1, curr);

        return ans;
    }
};