class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        vector<vector<int>> v(9, vector<int>(9, 0));

        for (auto& a : dominoes)
        {
            if (a[0] > a[1])
                v[a[1] - 1][a[0] - 1]++;
            else
                v[a[0] - 1][a[1] - 1]++;
        }

        int ans = 0;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (v[i][j] > 1)
                    ans += ((v[i][j] - 1) * v[i][j]) / 2;  // C_2_v[i][j]
            }
        }

        return ans;
    }
};