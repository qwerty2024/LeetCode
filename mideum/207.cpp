class Solution 
{
    bool dfs(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
    {
        if (recStack[u])
            return true;

        if (visited[u])
            return false;

        visited[u] = true;
        recStack[u] = true;

        for (int x : adj[u])
        {
            if (dfs(adj, x, visited, recStack))
                return true;
        }

        recStack[u] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);

        for (const auto& a : prerequisites)
        {
            adj[a[0]].push_back(a[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && dfs(adj, i, visited, recStack))
                return false; 
        }

        return true;
    }
};