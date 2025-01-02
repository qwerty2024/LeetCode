class Solution 
{
    unordered_set<char> us{'a', 'e', 'i', 'o', 'u'};

    int test(const string& s)
    {
        if (us.contains(s[0]) && us.contains(s[s.size() - 1]))
            return 1;

        return 0;
    }

public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) 
    {
        int n = w.size();
        int m = q.size();
        vector<int> ans(m, 0);

        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + test(w[i - 1]);
        }

        for (int i = 0; i < m; i++)
        {
            ans[i] = pref[q[i][1] + 1] - pref[q[i][0]];
        }

        return ans;
    }
};