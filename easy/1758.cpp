class Solution 
{
public:
    int minOperations(string s) 
    {
        int mini1 = 0;
        int mini2 = 0;

        char curr = '0';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != curr)
                mini1++;

            curr = curr == '0' ? '1' : '0';
        }

        curr = '1';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != curr)
                mini2++;

            curr = curr == '0' ? '1' : '0';
        }

        return min(mini1, mini2);
    }
};