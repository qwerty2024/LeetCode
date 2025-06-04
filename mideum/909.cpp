class Solution
{
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();

        for (int i = 0; i < n / 2; i++)
        {
            swap(board[i], board[n - i - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                for (int j = 0; j < n / 2; j++)
                {
                    swap(board[i][j], board[i][n - j - 1]);
                }
        }

        vector<int> adj(n * n + 1);

        int count = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == -1)
                {
                    adj[count] = count;
                }
                else
                {
                    adj[count] = board[i][j];
                }
                count++;
            }
        }

        vector<int> iters(n * n + 1, INT_MAX);
        iters[1] = 0;
        int iter = 0;
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int k = q.size();

            for (int i = 0; i < k; i++)
            {
                int pos = q.front();
                q.pop();

                for (int j = 1; j <= 6; j++)
                {
                    if (pos + j <= n * n && iters[adj[pos + j]] == INT_MAX)
                    {
                        iters[adj[pos + j]] = iters[pos] + 1; 
                        q.push(adj[pos + j]);
                    }
                }
            }

            if (iters[n * n] != INT_MAX)
                return iters[n * n];
        }

        return -1;
    }
};