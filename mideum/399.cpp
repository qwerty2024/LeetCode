class Solution
{
    bool flag = false;
    double res = 0.0;

    void dfs(unordered_map<string, unordered_map<string, double>>& data,
             unordered_set<string>& used,
             string node,
             string find_node,
             double coef)
    {
        used.insert(node);
        if (find_node == node)
        {
            flag = true;
            res = coef;
            return;
        }

        for (const auto& a : data[node])
        {
            if (!used.contains(a.first))
                dfs(data, used, a.first, find_node, coef * a.second);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, unordered_map<string, double>> data;

        for (int i = 0; i < values.size(); i++)
        {
            string left = equations[i][0];
            string right = equations[i][1];

            data[left][right] = values[i];
            data[right][left] = 1 / values[i];
        }

        vector<double> ans;

        for (const auto& q : queries)
        {
            if (!data.contains(q[0]) || !data.contains(q[1]))
            {
                ans.push_back(-1.0);
                continue;
            }

            if (q[0] == q[1])
            {
                ans.push_back(1.0);
                continue;
            }

            unordered_set<string> used;
            flag = false;
            res = -1.0;
            dfs(data, used, q[0], q[1], 1.0);
            ans.push_back(flag ? res : -1.0);
        }

        return ans;
    }
};