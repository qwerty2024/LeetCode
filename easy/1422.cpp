class Solution 
{
public:
    int maxScore(string s) 
    {
        int n = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == '1') n++;

        int zero = (s[0] == '0') ? 1 : 0;
        int maxi = zero + n;

        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                zero++;
            }
            else
            {
                n--;
            }
            maxi = max(maxi, zero + n);
        }


        return maxi;
    }
};