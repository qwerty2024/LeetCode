class Solution
{
public:
    int minCost(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        vector<vector<int>> used(m, vector<int>(n, 0));

        pq.push({0, {0, 0}});

        int ans = 0;
        while (!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second[0];
            int j = pq.top().second[1];

            if (i == m - 1 && j == n - 1)
            {
                ans = val;
                break;
            }

            pq.pop();

            if (j < n - 1 && (used[i][j] & 1) != 1)
            {
                pq.push({ ((1 == grid[i][j]) ? val : (val + 1)) , {i, j + 1} });
                used[i][j] |= 1;
            }

            if (j > 0 && (used[i][j] & 2) != 2)
            {
                pq.push({ ((2 == grid[i][j]) ? val : (val + 1)) , {i, j - 1} });
                used[i][j] |= 2;
            }

            if (i < m - 1 && (used[i][j] & 4) != 4)
            {
                pq.push({ ((3 == grid[i][j]) ? val : (val + 1)) , {i + 1, j} });
                used[i][j] |= 4;
            }

            if (i > 0 && (used[i][j] & 8) != 8)
            {
                pq.push({ ((4 == grid[i][j]) ? val : (val + 1)) , {i - 1, j} });
                used[i][j] |= 8;
            }
        }

        return ans;
    }
};