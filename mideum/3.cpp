class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();

        if (n == 0)
            return 0;

        vector<int> alph(256, 0);
        int ans = 0;
        int l = 0;
        int r = 0;
        alph[s[0]]++;

        while (true)
        {
            while (r < (n - 1) && alph[s[r + 1]] != 1)
            {
                r++;
                alph[s[r]]++;
            }

            ans = max(ans, r - l + 1);

            if (r == n - 1)
                break;

            while (s[l] != s[r + 1])
            {
                alph[s[l]]--;
                l++;
            }
            alph[s[l]]--;
                l++;
        }

        return ans;
    }
};