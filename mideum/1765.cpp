class Solution 
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size();
        int n = isWater[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    used[i][j] = true;
                    isWater[i][j] = 0;
                    pq.push({0, {i, j}});
                }
            }
        }

        vector<vector<int>> dim{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        while(!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            for (auto& a : dim)
            {
                int ii = i + a[0];
                int jj = j + a[1];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n && !used[ii][jj])
                {
                    used[ii][jj] = true;
                    isWater[ii][jj] = val + 1;
                    pq.push({val + 1, {ii, jj}});
                }
            }
        }

        return isWater;
    }
};