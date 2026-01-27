class Solution 
{
    vector<int> costs;
    unordered_map<int, vector<pair<int, int>>> um;

public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        for (int i = 0; i < edges.size(); i++)
        {
            um[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            um[edges[i][1]].push_back({edges[i][0], 2 * edges[i][2] });
        }

        costs.resize(n, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});
        costs[0] = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (wt > costs[u]) 
                continue;
            
            if (u == n - 1) 
                return wt;
            
            for(auto edge: um[u])
            {
                int v = edge.first;
                int w = edge.second;
                if (w + costs[u] < costs[v])
                {
                    costs[v] = w + costs[u];
                    pq.push({costs[v], v});
                }
            }
        }

        return -1;
    }
};