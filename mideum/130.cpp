class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> offset {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O')
                {
                    board[i][j] = 'Y';
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
                            if (xx >= 0 && yy >= 0 && xx < m && yy < n && board[xx][yy] == 'O')
                            {
                                board[xx][yy] = 'Y';
                                q.push({xx, yy});
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};