class Solution 
{   
    vector<vector<pair<int, int>>> adj;

    void fnk(vector<vector<int>>& costs, int host, int in, int val)
    {
        if (costs[host][in] > val)
        {
            costs[host][in] = val;

            for (int i = 0; i < adj[in].size(); i++)
            {
                fnk(costs, host, adj[in][i].first, val + adj[in][i].second);
            }
        }
        else
            return;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<int>> costs(26, vector<int>(26, INT_MAX));
        adj.resize(26);

        for (int i = 0; i < original.size(); i++)
        {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        for (int i = 0; i < 26; i++)
        {
            fnk(costs, i, i, 0);
        }

        //for (int i = 0; i < 26; i++)
        //{      
        //    for (int j = 0; j < 26; j++)
        //    {
        //        if (costs[i][j] != INT_MAX)
        //            cout << costs[i][j] << " ";
        //    }
        //    cout << "\n";
        //}

        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (costs[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                return -1;

            ans += costs[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};