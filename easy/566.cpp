class Solution 
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) return mat;

        vector<vector<int>> new_mat(r, vector<int>(c, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * n + j;

                new_mat[idx / c][idx % c] = mat[i][j];
            }
        }

        return new_mat;
    }
};