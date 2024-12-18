class Solution 
{
public:
    int possibleStringCount(string w) 
    {
        int n = w.size();
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            while (i < n && w[i] == w[i + 1])
            {
                i++;
                ans++;
            }
        }

        return ans;
    }
};