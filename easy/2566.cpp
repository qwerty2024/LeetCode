class Solution 
{
public:
    int minMaxDifference(int num) 
    {
        int maxi = 0;
        int mini = 0;

        string s = to_string(num);
        
        int i = 0;
        while (i < s.size() && s[i] == '9')
        {
            i++;
        }

        if (i == s.size()) i--;
        char ch = s[i];

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ch) s[j] = '9';
        }

        maxi = stoi(s);

        s = to_string(num);
        i = 0;
        while (i < s.size() && s[i] == '0')
        {
            i++;
        }

        if (i == s.size()) i--;
        ch = s[i];

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ch) s[j] = '0';
        }

        mini = stoi(s);

        return maxi - mini;
    }
};