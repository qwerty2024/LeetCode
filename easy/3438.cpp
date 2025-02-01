class Solution 
{
public:
    string findValidPair(string s) 
    {
        vector<int> v(10, 0);
        int n = s.size();
        
        for (int i = 0; i < n; i++)
        {
            v[s[i] - '0']++;
        }

        for (int i = 0; i < 10; i++)
        {
            if (v[i] == i) v[i] = -1;
        }

        string ss = "";
        for (int i = 1; i < n; i++)
        {
            if (v[s[i] - '0'] == -1 && v[s[i - 1] - '0'] == -1 && s[i - 1] != s[i])
            {
                ss += s[i - 1];
                ss += s[i];
                break;
            }
        }    

        return ss;
    }
};