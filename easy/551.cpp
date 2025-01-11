class Solution 
{
public:
    bool checkRecord(string s) 
    {
        int a = 0;
        int l = 0;
        int n = s.size();

        if (n == 1)
            return true;

        if (n == 2)
            return (s[0] == 'A' && s[1] == 'A') ? false : true;

        for (int i = 0; i < 3; i++)
        {
            if (s[i] == 'A')
            {   a++;
                l = 0;
            }
            else if (s[i] == 'L')
                l++;
            else if (s[i] != 'L')
                l = 0;
        }

        if (a > 1 || l == 3) return false;

        for (int i = 3; i < n; i++)
        {
            if (a > 1 || l == 3) return false;

            if (s[i] != 'L')
                l = 0;
            else if (s[i] == 'L')
                l++;

            if (s[i] == 'A')
                a++;
        } 

        if (a > 1 || l == 3) return false;

        return true;
    }
};