class Solution 
{
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool test = true;
                if (mat[i][j] == 1)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (k != i)
                        {
                            if (mat[k][j] != 0)
                                test = false;
                        }
                    }

                    for (int k = 0; k < n; k++)
                    {
                        if (k != j)
                        {
                            if (mat[i][k] != 0)
                                test = false;
                        }
                    }

                    if (test) ans++;
                }
            }
        }

        return ans;
    }
};