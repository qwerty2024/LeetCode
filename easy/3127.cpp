class Solution 
{
public:
    bool canMakeSquare(vector<vector<char>>& g) 
    {
        int test = 'B' * 2 + 'W' * 2;
        
        if (g[0][0] + g[0][1] + g[1][0] + g[1][1] != test)
            return true;

        if (g[1][0] + g[1][1] + g[2][0] + g[2][1] != test)
            return true;

        if (g[0][1] + g[0][2] + g[1][1] + g[1][2] != test)
            return true;

        if (g[1][1] + g[1][2] + g[2][1] + g[2][2] != test)
            return true;

        return false;
    }
};