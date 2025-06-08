class Solution 
{
    int len = 0;
    int m = 0;
    int n = 0;
    int _i = 0;
    int _j = 0;
    bool ans = false;
    vector<vector<bool>> used;    

    void backtr(const vector<vector<char>>& board, const string& word, int pos)
    {
        if (pos == len - 1)
        {
            if (word[pos] == board[_i][_j])
                ans = true;
            return;
        }

        if (word[pos] != board[_i][_j])
            return;

        used[_i][_j] = true;

        if (_j != 0 && used[_i][_j - 1] != true)
        {
            _j--;
            backtr(board, word, pos + 1);
            _j++;
        }

        if (_j != n - 1 && used[_i][_j + 1] != true)
        {
            _j++;
            backtr(board, word, pos + 1);
            _j--;
        }

        if (_i != 0 && used[_i - 1][_j] != true)
        {
            _i--;
            backtr(board, word, pos + 1);
            _i++;
        }

        if (_i != m - 1 && used[_i + 1][_j] != true)
        {
            _i++;
            backtr(board, word, pos + 1);
            _i--;
        }

        used[_i][_j] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        len = word.size();
        m = board.size();
        n = board[0].size();
        used.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                _i = i;
                _j = j;

                backtr(board, word, 0);
            }
        }
            
        return ans;
    }
};