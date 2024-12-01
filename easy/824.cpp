class Solution 
{
public:
    string toGoatLatin(string s) 
    {
        string ans = "";
        string close = "a";
        int i = 0;
        while (i < s.size())
        {
            string tmp;
            while (i < s.size() && s[i] != ' ')
            {
                tmp += s[i];
                i++;
            }

            if (tmp[0] == 'a' || tmp[0] == 'e' || tmp[0] == 'i' || tmp[0] == 'o' || tmp[0] == 'u' || 
                tmp[0] == 'A' || tmp[0] == 'E' || tmp[0] == 'I' || tmp[0] == 'O' || tmp[0] == 'U')
            {
                tmp += "ma";
            }
            else
            {
                tmp += tmp[0];
                tmp += "ma";
                tmp = tmp.substr(1, tmp.size() - 1);
            }

            tmp += close;

            ans += tmp + ' ';

            close += 'a';
            i++;
        }

        return ans.substr(0, ans.size() - 1);
    }
};