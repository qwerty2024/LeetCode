class Solution 
{
public:
    int numWays(vector<string>& w, string t) 
    {
        const int MOD = 1000000007;
        int m = w.size();
        int n = w[0].size();
        int k = t.size();

        vector<vector<int>> freq(n, vector<int>(26, 0));
        
        for (auto a : w)
        {
            for (int i = 0; i < n; i++)
            {
                freq[i][a[i] - 'a']++;
            }
        }

        vector<long long> prevCount(k + 1, 0);
        vector<long long> currCount(k + 1, 0);
        prevCount[0] = 1;

        for (int i = 1; i <= n; i++) 
        {
            currCount = prevCount;
            for (int j = 1; j <= k; j++) 
            {
                int curPos = t[j - 1] - 'a';
                currCount[j] += (freq[i - 1][curPos] * prevCount[j - 1]) % MOD;
                currCount[j] %= MOD;  
            }
            prevCount = currCount;
        }
        return currCount[k];
    }
};