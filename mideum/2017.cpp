class Solution 
{
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();

        vector<long long> suff(n + 1, 0);
        vector<long long> pref(n + 1, 0);

        for (int i = 1; i < n + 1; i++)
        {
            pref[i] = pref[i - 1] + grid[1][i - 1]; 
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + grid[0][i]; 
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, max(pref[i], suff[i + 1]));
        }

        return ans;
    }
};