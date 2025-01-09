class Solution 
{
public:
    int countPalindromicSubsequence(string s) 
    {
        int n = s.size();
        int ans = 0;
        for (int k = 0; k < 26; k++)
        {
            char ch = 'a' + k;

            unordered_set<char> us;
            int i = 0;
            int j = n - 1; 

            while (i < n - 1 && s[i] != ch)
            {
                i++;
            }

            while (j > 0 && s[j] != ch)
            {
                j--;
            }
            i++;

            while (i < j)
            {
                us.insert(s[i]);
                i++;
            }

            ans += us.size();
        }

        return ans;
    }
};