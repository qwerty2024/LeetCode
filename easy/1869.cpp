class Solution 
{
public:
    bool checkZeroOnes(string s) 
    {
        int len0 = 0;
        int len1 = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (s[i] == '1')
            {
                count++;
                while (i < n && s[i] == '1')
                {
                    count++;
                    i++;
                }
            }
            len1 = max(len1, count);
        }

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (s[i] == '0')
            {
                count++;
                while (i < n && s[i] == '0')
                {
                    count++;
                    i++;
                }
            }
            len0 = max(len0, count);
        }

        return len1 > len0;
    }
};