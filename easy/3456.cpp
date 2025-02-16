class Solution
{
public:
    bool hasSpecialSubstring(string s, int k)
    {
        int n = s.size();
        char ch = 'a';
        string tmp(k, 'a');
        int offset = 0;
        
        for (int i = 0; i < 26; i++)
        {
            offset = 0;
            for (int j = 0; j < k; j++)
                tmp[j] = ch;

            int t = 0;
            while (true)
            {    
                int t = s.find(tmp, offset);
                
                if (t == -1) 
                    break;
                
                int count = 0;
                int ind = t;
                while ((count + ind) < n && s[count + ind] == ch)
                {
                    count++;
                }

                if (count == k)
                    return true;

                offset = count + ind;
            }

            ch++;
        }

        return false;
    }
}; 