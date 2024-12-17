class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int i = s.size() - 1;

        while (i >= 0)
        {
            if (s[i] == ' ')
            {
                i--;
            }
            else break;
        }

        int r = i;
        while (i >= 0)
        {
            if (s[i] == ' ')
                break;
            else
                i--;
        }

        return r - i;
    }
};