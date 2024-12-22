class Solution 
{
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) 
    {        
        int n = h.size();
        int m = q.size();
        vector<int> ans(m, -1);

        vector<vector<int>> v(m, vector<int>(3, -1));

        for (int i = 0; i < m; i++)
        {
            if (q[i][0] > q[i][1])
            {
                v[i][0] = q[i][0];
                v[i][1] = q[i][1];
                v[i][2] = i;
            }
            else
            {
                v[i][0] = q[i][1];
                v[i][1] = q[i][0];
                v[i][2] = i;
            }
        }

        sort(v.begin(), v.end(), greater<>());

        vector<pair<int, int>> st;

        int i = n - 1;
        for (auto a : v)
        {
            int y = a[0];
            int x = a[1];
            if (x == y || h[x] < h[y])
            {
                ans[a[2]] = y;
                continue;
            }

            for (; i > y; i--)
            {
                while (!st.empty() && h[st.back().second] < h[i])
                    st.pop_back();

                st.emplace_back(h[i], i);
            }

            auto it = upper_bound(st.rbegin(), st.rend(), make_pair(h[x], n));
            ans[a[2]] = (it == st.rend()) ? -1 : it->second;
        }

        return ans;
    }
};