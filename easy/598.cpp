class Solution 
{
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        if (ops.size() == 0) return m * n;

        int mini_x = INT_MAX;
        int mini_y = INT_MAX;

        for (auto a : ops)
        {
            mini_x = min(a[0], mini_x);
            mini_y = min(a[1], mini_y);
        }

        return mini_x * mini_y;
    }
};