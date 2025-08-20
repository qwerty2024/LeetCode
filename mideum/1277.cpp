class Solution
{
public:
    int countSquares(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for (int j = 0; j < n; j++)
            ans += mat[0][j];

        for (int i = 1; i < m; i++)
            ans += mat[i][0];


        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[i][j] == 0)
                    continue;

                mat[i][j] = 1 + min(mat[i - 1][j - 1], min(mat[i - 1][j], mat[i][j - 1]));

                ans += mat[i][j];
            }
        }

        return ans;
    }
};