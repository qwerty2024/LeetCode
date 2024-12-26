class Solution 
{
    bool ans = false;
    int dest = 0;
    unordered_set<int> visited;

    void dfs(vector<vector<int>>& v, int root)
    {
        if (root == dest)
            ans = true;

        for (auto a : v[root])
        {
            if (!visited.contains(a))
            {
                visited.insert(a);
                dfs(v, a);
            }
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> v(n);
        for (int i = 0; i < edges.size(); i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }

        dest = destination;
        visited.insert(source);
        dfs(v, source);
        return ans;
    }
};