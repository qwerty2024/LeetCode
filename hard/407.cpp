class Solution 
{
public:
    int trapRainWater(vector<vector<int>>& hM) 
    {
        int m = hM.size();
        int n = hM[0].size();

        vector<vector<bool>> used(m, vector<bool>(n, false));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
                    pq.push({hM[i][j], {i, j}});
                    used[i][j] = true;
                }
            }
        }

        vector<vector<int>> direction{ {0,1}, {0,-1}, {1,0}, {-1,0} };
        int ans = 0;
        while (!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second[0];
            int j = pq.top().second[1];
            pq.pop();

            for (auto a : direction)
            {
                int ii = i + a[0];
                int jj = j + a[1];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n && !used[ii][jj])
                {
                    if (val - hM[ii][jj] > 0)
                    {
                        ans += val - hM[ii][jj];
                        pq.push({val, {ii, jj}});
                    }
                    else
                    {
                        pq.push({hM[ii][jj], {ii, jj}});
                    }

                    used[ii][jj] = true;
                }
            }
        }
        
        return ans;
    }
};