class Solution 
{
public:
    int minimumLength(string s) 
    {
        vector<int> v(26, 0);

        for (auto& a : s)
            v[a - 'a']++;

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
                ans += v[i] % 2 == 0 ? 2 : 1;
        }

        return ans;
    }
};