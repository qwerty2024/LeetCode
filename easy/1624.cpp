class Solution 
{
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        vector<int> dict(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            if (dict[s[i] - 'a'] == -1)
            {
                dict[s[i] - 'a'] = i;
            }
        }

        int maxi = -1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i > dict[s[i] - 'a'] && dict[s[i] - 'a'] != -1)
            {
                maxi = max(maxi, i - dict[s[i] - 'a'] - 1);
            }
        }
 
        return maxi;
    }
};