class Solution 
{
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) 
    {
        for (auto& a : grid)
            sort(a.begin(), a.end(), greater<int>());

        priority_queue<int> pq;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < limits[i]; j++)
            {
                pq.push(grid[i][j]);
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans += pq.top();
            pq.pop();        
        }

        return ans;
    }
};