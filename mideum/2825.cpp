class Solution 
{
public:
    bool canMakeSubsequence(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();
        
        if (m > n) return false;

        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (s1[i] == s2[j] || (s1[i] + 1) == s2[j] || (s1[i] == 'z' && s2[j] == 'a'))
            {
                j++;
            }

            i++;
        }

        return j == m;
    }
};
