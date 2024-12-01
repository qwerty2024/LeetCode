class Solution 
{
public:
    vector<int> numberOfLines(vector<int>& widths, string s) 
    {
        int n = s.size();
        int n_str = 1;

        int count = 100;
        int i = 0;
        while (i < n)
        {
            if (count - widths[s[i] - 'a'] < 0)
            {
                n_str++;
                count = 100 - widths[s[i] - 'a'];
            }
            else
            {
                count -= widths[s[i] - 'a'];
            }
            i++;
        }

        return {n_str, 100 - count};
    }
};