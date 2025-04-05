class Solution 
{
public:
    int reverseDegree(string s) 
    {
        int ans = 0;

        int j = 26;
        vector<int> abc(26, 0);
        for (int i = 0; i < 26; i++)
        {
            abc[i] = j;
            j--;
        }

        for (int i = 0; i < s.size(); i++)
        {
            ans += abc[s[i] - 'a'] * (i + 1);
        }

        return ans;
    }
};