class Solution 
{
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string ans = "";
        int j = 0;
        int i = 0;
        while (i < s.size())
        {
            if (j < spaces.size() && i == spaces[j])
            {
                ans += ' ';
                ans += s[i];
                j++;
            }
            else
            {
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};