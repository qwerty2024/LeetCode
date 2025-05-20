class Solution 
{
public:
    bool isPrefixString(string s, vector<string>& words) 
    {
        int n = s.size();
        int curr = 0;

        for (const auto& a : words)
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (curr == n + 1)
                    return false;

                if (s[curr++] != a[i])
                    return false;
            }

            if (curr == n)
                return true;
        }

        return false;
    }
};