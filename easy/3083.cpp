class Solution 
{
public:
    bool isSubstringPresent(string s) 
    {
        unordered_set<string> us;

        for (int i = 1; i < s.size(); i++)
        {
            string tmp = "";
            tmp += s[i - 1];
            tmp += s[i];
            us.insert(tmp);
        }

        reverse(s.begin(), s.end());

        for (int i = 1; i < s.size(); i++)
        {
            string tmp = "";
            tmp += s[i - 1];
            tmp += s[i];
            if (us.contains(tmp)) return true;
        }

        return false;
    }
};