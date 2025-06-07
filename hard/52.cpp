class Solution 
{
    int _n;
    int ans = 0;
    vector<vector<int>> table;

    void set(int _i, int _j)
    {
        int mask = 1 << _i;
        for (int i = 0; i < _n; i++)
        {
            if (_i + i >= 0 && _i + i <_n && _j + i >= 0 && _j + i < _n)
                table[_i + i][_j + i] |= mask;
            if (_i + i >= 0 && _i + i <_n && _j - i >= 0 && _j - i < _n)
                table[_i + i][_j - i] |= mask;

            if (_i >= 0 && _i <_n && _j + i >= 0 && _j + i < _n)
                table[_i][_j + i] |= mask;
            if (_i + i >= 0 && _i + i <_n && _j >= 0 && _j < _n)
                table[_i + i][_j] |= mask;
            
            if (_i >= 0 && _i <_n && _j - i >= 0 && _j - i < _n)
                table[_i][_j - i] |= mask;
        }
    }

    void unset(int _i, int _j)
    {
        int mask = 1 << _i;
        table[_i][_j] ^= mask;
        for (int i = 1; i < _n; i++)
        {
            if (_i + i >= 0 && _i + i <_n && _j + i >= 0 && _j + i < _n)
                table[_i + i][_j + i] ^= mask;
            if (_i + i >= 0 && _i + i <_n && _j - i >= 0 && _j - i < _n)
                table[_i + i][_j - i] ^= mask;

            if (_i >= 0 && _i <_n && _j + i >= 0 && _j + i < _n)
                table[_i][_j + i] ^= mask;
            if (_i + i >= 0 && _i + i <_n && _j >= 0 && _j < _n)
                table[_i + i][_j] ^= mask;
            
            if (_i >= 0 && _i <_n && _j - i >= 0 && _j - i < _n)
                table[_i][_j - i] ^= mask;
        }
    }

    void backtr(int i)
    {
        if (i == _n)
            ans++;

        if (i >= _n)
            return;

        for (int j = 0; j < _n; j++)
        {
            if (table[i][j] != 0)
                continue;

            set(i, j);

            backtr(i + 1);

            unset(i, j);
        }
    }

public:
    int totalNQueens(int n) 
    {
        _n = n;
        table.resize(n, vector<int>(n, 0));

        backtr(0);

        return ans;
    }
};