class Solution
{
    long long ans = INT_MIN;
    vector<int> used; // запомнить путь боба
    vector<vector<int>> sp; // список смежности

    bool dfs_bob_path(int root, int prev, int lvl)
    {
        int ret = -1;

        for (const auto& a : sp[root])
        {
            if (a != prev)
            {
                if (a == 0)
                {
                    used[0] = lvl;
                    return true;
                }
                else
                {
                    if (dfs_bob_path(a, root, lvl + 1))
                    {
                        used[a] = lvl;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    void dfs(vector<int>& amount, int root, int prev, int lvl, long long sum)
    {
        if (root != 0 && sp[root].size() == 1)
        {
            if (used[root] == -1)
            {
                ans = max(ans, sum + amount[root]);
            }
            else if (lvl > used[root])
            {
                ans = max(ans, sum);
            }
            else if (lvl == used[root])
            {
                ans = max(ans, sum + amount[root] / 2);
            }
            else
            {
                ans = max(ans, sum + amount[root]);
            }   

            return;
        }

        for (const auto& a : sp[root])
        {
            if (a != prev)
            {
                if (used[root] == -1)
                {
                    dfs(amount, a, root, lvl + 1, sum + amount[root]);
                }
                else if (lvl > used[root])
                {
                    dfs(amount, a, root, lvl + 1, sum);
                }
                else if (lvl == used[root])
                {
                    dfs(amount, a, root, lvl + 1, sum + amount[root] / 2);
                }
                else
                {
                    dfs(amount, a, root, lvl + 1, sum + amount[root]);
                }
            }
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        int n = 0;

        for (const auto& a : edges)
        {
            n = max(n, max(a[0], a[1]));
        }

        n++;
        
        sp.resize(n);
        for (const auto& a : edges)
        {
            sp[a[0]].push_back(a[1]);
            sp[a[1]].push_back(a[0]);
        }

        used.resize(n, -1);

        // найти путь от нуля до боба, что бы если что учесть пересечение
        used[bob] = 0;
        dfs_bob_path(bob, -1, 1);

        // алиса идет и проверяет на каком тике тут был боб, если что делит или добавляет в результат
        dfs(amount, 0, -1, 0, 0);

        return ans;
    }
};