class Solution 
{
public:
    vector<int> minOperations(string b) 
    {
        int n = b.size();
        vector<int> pref(n + 1, 0);
        vector<int> suff(n + 1, 0);
        int curr = 0;

        for (int i = 1; i <= n; i++)
        {
            if (b[i - 1] == '1') curr++;
            pref[i] = pref[i - 1] + curr;
        }

        curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] == '1') curr++;
            suff[i] = suff[i + 1] + curr;
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = pref[i] + suff[i + 1];
        }

        return ans;
    }
};