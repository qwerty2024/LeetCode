class Solution 
{
public:
    bool hasMatch(string s, string p) 
    {
        if (p[0] == '*')
        {
            string tmp = p.substr(1, p.size() - 1);
            if (s.find(tmp) != string::npos)
                return true;
            else
                return false;
        }

        if (p[p.size() - 1] == '*')
        {
            p.pop_back();
            if (s.find(p) != string::npos)
                return true;
            else
                return false;
        }

        string tmp = "";
        int i = 0;
        while (i < p.size() && p[i] != '*')
        {
            tmp += p[i];
            i++;
        }
        int len = tmp.size();

        int id = s.find(tmp);

        if (id != string::npos)
        {
            tmp = s.substr(id + len, s.size() - (id + len));
            if (tmp.find(p.substr(i + 1, p.size() - i - 1)) != string::npos)
            {
                return true;
            }
        }

        return false;
    }
};