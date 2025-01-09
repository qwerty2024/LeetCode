class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> um;
        for (auto a : s)
        {
            um[a]++;
        }

        int ans = 0;
        bool flag = false;

        for (auto a : um)
        {
            if (a.second % 2 == 1) 
            {
                flag = true;
                ans += a.second - 1;
            }
            else
                ans += a.second;
        }

        return ans + (flag ? 1 : 0);
    }
};