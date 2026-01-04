class Solution 
{
public:
    int findTheLongestBalancedSubstring(string s) 
    {
        int maxi = 0;
        int i = 0;
        int n = s.size();

        while (i < n)
        {
            if (s[i] == '0')
            {
                int cntZero = 0;
                while (i < n && s[i] == '0')
                {
                    cntZero++;
                    i++;
                }

                int cntOne = 0;
                while (i < n && s[i] == '1')
                {
                    cntOne++;
                    i++;
                }

                maxi = max(maxi, min(cntOne, cntZero) * 2);
            }
            else
                i++;
        }


        return maxi;
    }
};