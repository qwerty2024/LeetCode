class Solution
{
    int indx(int& i, int& j)
    {
        int ans = i;
        ans <<= 10;
        ans += j;
        return ans;
    }

    inline int row(int num)
    {
        num >>= 10;
        return num;
    }

    inline int col(int num)
    {
        return (num & 511);
    }

public:
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        //unordered_map<int, vector<int>> um;
        vector<bool> used_r(m, false);
        vector<bool> used_c(n, false);

        queue<int> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && (!used_r[i] || !used_c[j]))
                {
                    q.push(indx(i, j));

                    int sum = 1;

                    while (!q.empty())
                    {
                        int ii = row(q.front());
                        int jj = col(q.front());

                        q.pop();

                        if (!used_r[ii])
                        {
                            for (int k = 0; k < n; k++)
                            {
                                if (grid[ii][k] == 1 && jj != k && !used_c[k])
                                {
                                    q.push(indx(ii, k));
                                    sum++;
                                }
                            }
                        }

                        if (!used_c[jj])
                        {
                            for (int k = 0; k < m; k++)
                            {
                                if (grid[k][jj] == 1 && ii != k && !used_r[k])
                                {
                                    q.push(indx(k, jj));
                                    sum++;
                                }
                            }
                        }

                        used_r[ii] = true;
                        used_c[jj] = true;
                    }

                    if (sum > 1) ans += sum;
                }
            }
        }

        return ans;
    }
};