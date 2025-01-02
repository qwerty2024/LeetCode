
class Solution 
{
public:
    string modifyString(string s) 
    {
        int n = s.size();
        int i = 0;
        int j = 0;

        // если первый символ ?
        if (s[0] == '?')
        {
            while (j < n && s[j] == '?')
                j++;
            
            if (j == n) 
                s[0] = 'a';
            else 
            {
                char ch = 'a' - 1;
                for (int k = 0; k < 26; k++)
                {
                    ch = ch + 1;
                    if (s[j] != ch)
                        break;
                }

                s[0] = ch;
            }
        }

        // если последний символ ?
        j = n - 1;
        if (s[n - 1] == '?')
        {
            while (j >= 0 && s[j] == '?')
                j--;
            
            char ch = 'a' - 1;
            for (int k = 0; k < 26; k++)
            {
                ch = ch + 1;
                if (s[j] != ch)
                    break;
            }

            s[n - 1] = ch;
        }

        // основа
        i = 0;
        j = 0;
        while (i < n)
        {
            while (i < n && s[i] != '?')
            {
                i++;
            }

            j = i;

            while (j < n && s[j] == '?')
            {
                j++;
            }

            char ch1 = 'a' - 1;
            char ch2 = 'a' - 1;
            for (int k = 0; k < 26; k++)
            {
                ch1 = ch1 + 1;
                if (s[j] != ch1 && s[i - 1] != ch1)
                    break;
            }

            for (int k = 0; k < 26; k++)
            {
                ch2 = ch2 + 1;
                if (s[j] != ch2 && s[i - 1] != ch2 && ch1 != ch2)
                    break;
            }

            for (int k = i; k < j; k++)
            {
                if (k % 2 == 0)
                    s[k] = ch1;
                else
                    s[k] = ch2;
            }
        }

        return s;
    }

};