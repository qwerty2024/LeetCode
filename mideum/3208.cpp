class Solution 
{
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
        int n = colors.size();
        int i = 0;
        int j = 1;
        int ans = 0;
        int len = 1;

        for (int t = 0; t < k; t++)
            colors.push_back(colors[t]);

        while (i < n + k - 2)
        {
            if (colors[i] == colors[j])
            {
                len = 1;
            }
            else
            {
                len++;
            }

            if (len >= k) ans++;

            i++;
            j++;
        }

        return ans;
    }
};