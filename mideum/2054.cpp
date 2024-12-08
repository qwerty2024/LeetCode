class Solution
{
    struct Cmp
    {
        bool operator() (const vector<int>& a, const int& b)
        {
            return a[0] < b;
        }
    };

public:
    int maxTwoEvents(vector<vector<int>>& ev)
    {
        int n = ev.size();

        sort(ev.begin(), ev.end());

        int curr = ev[n - 1][2];
        for (int i = n - 1; i >= 0; i--)
        {
            if (curr < ev[i][2])
            {
                curr = ev[i][2];
            }
            ev[i].push_back(curr);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int f = ev[i][1] + 1;

            // ищем индекс, если есть то проверяем сумму
            auto it = lower_bound(ev.begin(), ev.end(), f, Cmp());

            if (it != ev.end())
            {
                ans = max(ans, ev[i][2] + (*it)[3]);
            }
            else
            {
                ans = max(ans, ev[i][2]);
            }
        }

        return ans;
    }
};