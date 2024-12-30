class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int power = 0;
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans += pow(26, power) * (s[i] - 'A' + 1);
            power++;
        }

        return ans;
    }
};