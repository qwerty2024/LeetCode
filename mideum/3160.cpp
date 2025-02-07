class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        int n = queries.size();

        vector<int> ans(n, 0);
        unordered_map<int, int> tmp;
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            if (!tmp.contains(queries[i][0]))
            {
                tmp[queries[i][0]] = queries[i][1];
                um[queries[i][1]]++;
            }
            else
            {
                um[tmp[queries[i][0]]]--;
                if (um[tmp[queries[i][0]]] == 0) um.erase(tmp[queries[i][0]]);

                tmp[queries[i][0]] = queries[i][1];
                um[queries[i][1]]++;
            }

            ans[i] = um.size();
        }

        return ans;
    }
};