class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
        {
            vector<int> test(10, 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] >= '0' && board[i][j] <= '9')
                {
                    test[board[i][j] - '0']++;
                    if (test[board[i][j] - '0'] == 2)
                        return false;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            vector<int> test(10, 0);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] >= '0' && board[j][i] <= '9')
                {
                    test[board[j][i] - '0']++;
                    if (test[board[j][i] - '0'] == 2)
                        return false;
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                vector<int> test(10, 0);
                for (int ii = i * 3; ii < (i + 1) * 3; ii++)
                {
                    for (int jj = j * 3; jj < (j + 1) * 3; jj++)
                    {
                        if (board[ii][jj] >= '0' && board[ii][jj] <= '9')
                        {
                            test[board[ii][jj] - '0']++;
                            if (test[board[ii][jj] - '0'] == 2)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};