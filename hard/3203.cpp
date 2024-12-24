class Solution
{
    int f1 = -1;
    int f2 = -1;
    int max_dpth = -1;

    int dfs(vector<vector<int>>& list, int root, int prev, int dpth, int& ans)
    {
        int maxi = -1;
        for (auto a : list[root])
        {
            if (a != prev)
            {
                maxi = max(maxi, dfs(list, a, root, dpth + 1, ans));
            }
        }

        if (list[root].size() == 1)
        {
            if (max_dpth < dpth)
            {
                max_dpth = dpth;
                ans = root;
                return dpth;
            }
        }

        return maxi;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2)
    {
        if (e1.size() == 0 && e2.size() == 0) return 1;
        
        if (e1.size() == 0)
        {
            int m = 0;
            for (auto a : e2)
            {
                m = max(m, max(a[0], a[1]));
            }
            m++;
            vector<vector<int>> l2(m);
            for (auto a : e2)
            {
                l2[a[0]].push_back(a[1]);
                l2[a[1]].push_back(a[0]);
            }
            dfs(l2, 0, -1, 0, f2);
            max_dpth = -1;
            int d2 = dfs(l2, f2, -1, 0, f1);
            return d2 == 1 ? 2 : d2;
        }
 
        if (e2.size() == 0)
        {
            int n = 0;
            for (auto a : e1)
            {
                n = max(n, max(a[0], a[1]));
            }
            n++;
            vector<vector<int>> l1(n);
            for (auto a : e1)
            {
                l1[a[0]].push_back(a[1]);
                l1[a[1]].push_back(a[0]);
            }
            dfs(l1, 0, -1, 0, f1);
            max_dpth = -1;
            int d1 = dfs(l1, f1, -1, 0, f2);
            return d1 == 1 ? 2 : d1;
        }

        int n = 0;
        for (auto a : e1)
        {
            n = max(n, max(a[0], a[1]));
        }

        int m = 0;
        for (auto a : e2)
        {
            m = max(m, max(a[0], a[1]));
        }

        n++; m++;

        vector<vector<int>> l1(n);
        vector<vector<int>> l2(m);

        for (auto a : e1)
        {
            l1[a[0]].push_back(a[1]);
            l1[a[1]].push_back(a[0]);
        }

        for (auto a : e2)
        {
            l2[a[0]].push_back(a[1]);
            l2[a[1]].push_back(a[0]);
        }

        dfs(l1, 0, -1, 0, f1);
        max_dpth = -1;
        int d1 = dfs(l1, f1, -1, 0, f2);

        max_dpth = -1;

        dfs(l2, 0, -1, 0, f2);
        max_dpth = -1;
        int d2 = dfs(l2, f2, -1, 0, f1);

        if (((d1 + 1) / 2 + 1) < (d2 + 1) / 2) return d2;
        if (((d2 + 1) / 2 + 1) < (d1 + 1) / 2) return d1;

        d1 = (d1 + 1) / 2;
        d2 = (d2 + 1) / 2;

        return d1 + d2 + 1;
    }
};