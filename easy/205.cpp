class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> m;
        set<char> used;

        int n = s.size();
        int i = 0;
        while(i < n)
        {
            if (m.contains(s[i]))
            {
                if (m[s[i]] != t[i]) return false;
            }
            else
            {
                m[s[i]] = t[i];

                if (used.contains(t[i]))
                    return false;

                used.insert(t[i]);
            }

            i++;
        }

        
        return true;
    }
};