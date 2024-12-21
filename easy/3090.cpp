class Solution
{
    bool test(const string& s, int start, int fin)
    {
        vector<int> v(26, 0);
        for (int i = start; i <= fin; i++)
        {
            v[s[i] - 'a']++;

            if (v[s[i] - 'a'] > 2)
            {
                return false;
            }
        }

        return true;
    }
public:
    int maximumLengthSubstring(string s)
    {
        int maxi = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (test(s, i, j))
                    maxi = max(maxi, j - i + 1);
                else
                    break;
            }
        }

        return maxi;
    }
};