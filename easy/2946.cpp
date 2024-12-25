class Solution 
{
public:
    bool areSimilar(vector<vector<int>>& mat, int k) 
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> tmp(m, vector<int>(n, 0));

        k = k % n;

        if (k == 0) return true;

        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    tmp[i][(j - k < 0) ? n - (k - j) : j - k] = mat[i][j];
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    tmp[i][(j + k) % n] = mat[i][j];
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tmp[i][j] != mat[i][j])
                    return false;
            }
        }

        return true;
    }
};