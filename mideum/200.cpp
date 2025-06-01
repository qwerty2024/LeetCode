class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<pair<int, int>> offset {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!used[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (auto [dx, dy] : offset)
                        {
                            int xx = x + dx;
                            int yy = y + dy;
                            if (xx >= 0 && yy >= 0 && xx < m && yy < n && !used[xx][yy] && grid[xx][yy] == '1')
                            {
                                used[xx][yy] = true;
                                q.push({xx, yy});
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};