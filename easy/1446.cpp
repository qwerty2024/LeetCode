class Solution 
{
public:
    int maxPower(string s)
    {
        int n = s.size();
        int ans = 1;
        int i = 1;
        while (i < n)
        {
            int count = 1;
            while (i < n && s[i] == s[i - 1])
            {
                count++;
                i++;
            }

            ans = max(ans, count);
            i++;
        }

        return ans;
    }
};