class Solution 
{
public:
    int rearrangeCharacters(string s, string target) 
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto a : s)
            v1[a - 'a']++;

        for (auto a : target)
            v2[a - 'a']++;

        int ans = INT_MAX;

        for (int i = 0; i < 26; i++)
        {
            if (v2[i] > 0)
                ans = min(ans, v1[i] / v2[i]);
        }

        return ans;
    }
};