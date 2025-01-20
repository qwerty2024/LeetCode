class Solution 
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> count_row(m, 0);
        vector<int> count_col(n, 0);

        vector<pair<int, int>> v(n * m + 1);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[mat[i][j]] = {i, j};
            }
        }

        int ans = 0;
        for (auto& a : arr)
        {
            count_row[v[a].first]++;
            count_col[v[a].second]++;
            
            if (count_row[v[a].first] == n || count_col[v[a].second] == m)
                break;

            ans++;
        }

        return ans;
    }
};