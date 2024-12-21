class Solution
{
    unordered_map<int, pair<int, unordered_set<int>>> list;
    int ans = 0;
    int mod = -1;

    long long dfs(int root, int prev)
    {
        long long sum = list[root].first;
        for (auto a : list[root].second)
        {
            if (a != prev)
            {
                sum += dfs(a, root);
            }
        }

        if (sum % mod == 0)
        {
            ans++;
            return 0;
        }
        else
        {
            return sum;
        }

        return 0;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& ed, vector<int>& values, int k)
    {
        mod = k;

        for (int i = 0; i < n - 1; i++)
        {
            list[i].first = values[i];
            list[ed[i][0]].second.insert(ed[i][1]);
            list[ed[i][1]].second.insert(ed[i][0]);
        }
        list[n - 1].first = values[n - 1];

        dfs(0, -1);

        return ans;
    }
};