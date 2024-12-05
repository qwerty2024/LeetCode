class Solution 
{
public:
    int numberOfAlternatingGroups(vector<int>& c) 
    {
        int n = c.size();
        int ans = 0;

        if (c[0] != c[1] && c[0] != c[n - 1])
            ans++;

        if (c[n - 1] != c[n - 2] && c[n - 1] != c[0])
            ans++;

        for (int i = 1; i < n - 1; i++)
        {
            if (c[i] != c[i - 1] && c[i] != c[i + 1])
                ans++;
        }

        return ans;
    }
};