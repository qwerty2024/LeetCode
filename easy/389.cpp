class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            v1[s[i] - 'a']++;
            v2[t[i] - 'a']++;
        }
        v2[t[n] - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (v1[i] != v2[i])
                return (char)(i + 'a');
        }

        return '0';
    }
};