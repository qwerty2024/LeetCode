class Solution 
{
    bool isPrefixAndSuffix(const string& s1, const string& s2)
    {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;

        int i = 0;
        while (i < n)
        {
            if (s1[i] != s2[i]) return false;
            if (s1[n - i - 1] != s2[m - i - 1]) return false;
            i++;
        }

        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& w) 
    {
        int ans = 0;
        for (int i = 0; i < w.size() - 1; i++)
        {
            for (int j = i + 1; j < w.size(); j++)
            {
                if (isPrefixAndSuffix(w[i], w[j])) ans++;
            }
        }

        return ans;
    }
};