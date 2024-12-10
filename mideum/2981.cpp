class Solution 
{
public:
    int maximumLength(string s) 
    {
        int n = s.size();
        int i = 0;
        vector<vector<int>> v(26, vector<int>(50, 0));

        while (i < n)
        {
            int count = 1;
            char ch = s[i++];
            while (i < n && s[i] == ch)
            {
                count++;
                i++;
            }

            int idx = ch - 'a';
            int step = count;
            for (int j = 0; j < count; j++)
            {
                v[idx][j] += step--;
            }
        }

        int ans = -1;

        for (i = 0; i < 26; i++)
        {
            int maxi = -1;
            for (int j = 0; j < 50; j++)
            {
                if (v[i][j] > 2)
                    maxi = j + 1;
            }
            ans = max(ans, maxi);
        }

        return ans;
    }
};