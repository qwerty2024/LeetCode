class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        int prev = 0;
        int curr = 1;
        int i = 0;
        char ch = s[0];
        int n = s.size();
        int ans = 0;

        while (i < n && s[i] == ch)
        {
            prev++;
            i++;
        }

        while (i < n)
        {
            ch = s[i];
            curr = 0;
            while (i < n && s[i] == ch)
            {
                curr++;
                i++;
            }

            ans += min(prev, curr);
            prev = curr;
        }

        return ans;
    }
};