class Solution 
{
    bool isPref(const string& s, const string& pref)
    {
        if (s.size() < pref.size()) return false;

        int i = 0;
        while (i < pref.size())
        {
            if (s[i] != pref[i])
                return false;
            i++;
        }

        return true;
    }

public:
    int isPrefixOfWord(string s, string searchWord) 
    {
        int n = s.size();
        int i = 0;
        int count = 0;
        while (i < n)
        {
            string tmp = "";
            while (i < n && s[i] != ' ')
            {
                tmp += s[i];
                i++;
            }

            count++;

            if (isPref(tmp, searchWord))
                return count;

            i++;
        }

        return -1;
    }
};