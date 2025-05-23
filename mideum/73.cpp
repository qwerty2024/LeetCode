class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        pair<int, int> saved {-1, -1};    

        bool test = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    saved = {i, j};
                    test = true;
                    break;
                }
            }

            if (test)
                break;
        }

        if (!test)
            return;

        for (int i = 0; i < m; i++)
        {
            if (i != saved.first)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j != saved.second && matrix[i][j] == 0)
                    {
                        matrix[saved.first][j] = 0;
                        matrix[i][saved.second] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (i != saved.first)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j != saved.second && (matrix[i][saved.second] == 0 || matrix[saved.first][j] == 0))
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            matrix[i][saved.second] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            matrix[saved.first][j] = 0;
        }
    }
};