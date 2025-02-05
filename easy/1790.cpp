class Solution 
{
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        int n = s1.size();

        int f = -1;
        int s = -1;

        for (int i = 0; i < n; i++)
        {
            //cout << i << endl;
            if (f == -1 && s1[i] != s2[i])
            {
                f = i;
                continue;
            }

            if (s == -1 && s1[i] != s2[i])
            {
                s = i;
                continue;
            }

            if (f != -1 && s != -1)
                for (; i < n; i++)
                {
                    if (s1[i] != s2[i])
                        return false;
                }
        }
        
        //cout << f << " " << s << endl;

        if (f == -1)
            return true;
        
        if (s == -1)
            return false;

        return ((s1[f] == s2[s]) && (s1[s] == s2[f]));
    }
};