class Solution 
{
    bool test(vector<int>& t1, vector<int>& t2)
    {
        for (int i = 0; i < 26; i++)
        {
            if ((t1[i] == 0 && t2[i] != 0) || (t1[i] != 0 && t2[i] == 0))
                return false;
        }

        return true;
    }

public:
    string longestNiceSubstring(string s) 
    {
        int n = s.size();
        string ans = "";
        
        for (int i = 0; i < n; i++)
        {
            vector<int> t1(26, 0);
            vector<int> t2(26, 0);

            for (int j = i; j < n; j++)
            {
                if (s[j] >= 'a' && s[j] <= 'z')
                    t1[s[j] - 'a']++;

                if (s[j] >= 'A' && s[j] <= 'Z')
                    t2[s[j] - 'A']++;
                
                if (test(t1, t2))
                {
                    if (j - i + 1 > ans.size())
                        ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
};