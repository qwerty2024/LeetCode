class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
            return s;

        int count_z = s.size() / (numRows + (numRows - 2)) + 1;

        vector<string> data(numRows, string(count_z * (numRows + (numRows - 2)), ' '));

        int i = 0;
        int j = 0;
        int curr = 0;

        while (curr < s.size())
        {
            while (curr < s.size() && i < numRows)
            {
                data[i++][j] = s[curr++];
            }
            i -= 2;
            j++;

            for (int k = 0; curr < s.size() && k < numRows - 2; k++)
            {
                data[i][j] = s[curr++];
                i--;
                j++;
            }
        }

        string ans = "";

        for (int k = 0; k < numRows; k++)
        {
            for (int p = 0; p < data[0].size(); p++)
            {
                if (data[k][p] != ' ')
                    ans += data[k][p];
            }
        }

        return ans;
    }
};