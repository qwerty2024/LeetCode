class Solution 
{
public:
    string removeOccurrences(string s, string part) 
    {
        int n = s.size();
        int m = part.size();

        while (true)
        {
            size_t found = s.find(part);

            if (found == -1) break;

            s = s.substr(0, found) + s.substr(found + m, n - (found + m));
        }

        return s;
    }
};