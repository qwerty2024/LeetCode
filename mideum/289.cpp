class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> offsets{{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = 0;

                for (const auto& [x, y] : offsets)
                {
                    int xx = i + x;
                    int yy = j + y;

                    if (xx >= 0 && yy >= 0 && xx < m && yy < n)
                    {
                        if (board[xx][yy] == 1 || board[xx][yy] == 4 || board[xx][yy] == 5)
                            sum++;
                    }
                }

                if (board[i][j] == 1)
                {
                    if (sum == 2 || sum == 3)
                        board[i][j] = 4;
                    else
                        board[i][j] = 5;
                }
                else
                {
                    if (sum == 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (board[i][j] == 3 || board[i][j] == 4)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};