class Solution 
{
    bool test = true;
    void topSort(vector<vector<int>>& adj,
                 vector<bool>& used,
                 vector<bool>& recStack,
                 stack<int>& st, int node)
    {
        if (recStack[node])
            test = false;

        if (used[node])
            return;

        used[node] = true;
        recStack[node] = true;

        for (const auto& a : adj[node])
        {
            topSort(adj, used, recStack, st, a);
        }

        recStack[node] = false;
        st.push(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<bool> used(numCourses, false);
        vector<vector<int>> adj(numCourses);

        for (const auto& a : prerequisites)
        {
            adj[a[1]].push_back(a[0]);
        }

        stack<int> st;
        vector<bool> recStack(numCourses, false);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++)
            if (!used[i])
            {
                topSort(adj, used, recStack, st, i);
                if (!test)
                    return ans;
            }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};