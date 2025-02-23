class Solution 
{
public:
    bool hasSameDigits(string s) 
    {
        int n = s.size();
        while (true)
        {
            string tmp = "";

            if (s.size() == 2)
                break;
            
            for (int i = 1; i < s.size(); i++)
            {
                tmp += to_string((s[i - 1] + s[i]) % 10);
            }

            s = tmp;
        }

        if (s[0] == s[1])
            return true;

        return false;
    }
};