class Solution 
{
    bool one_diff(const string& a, const string& b)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
            if (a[i] != b[i])
                count++;
        return count == 1;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        bool test = true;
        for (int i = 0; i < bank.size(); i++)
        {
            if (startGene == bank[i])
            {
                test = false;
                break;
            }
        }

        if (test)
            bank.push_back(startGene);

        int n = bank.size();

        vector<vector<int>> adj(n);
        int start = 0;
        int end = -1;
        for (int i = 0; i < n; i++)
        {
            if (startGene == bank[i])
                start = i;

            if (endGene == bank[i])
                end = i;

            for (int j = i + 1; j < n; j++)
            {
                if (one_diff(bank[i], bank[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if (end == -1)
            return -1;

        vector<int> used(n, INT_MAX);
        queue<int> q;
        q.push(start);
        used[start] = 0;

        while (!q.empty())
        {
            int k = q.size();

            for (int i = 0; i < k; i++)
            {
                int pos = q.front();
                q.pop();

                for (auto a : adj[pos])
                {
                    if (used[a] == INT_MAX)
                    {
                        used[a] = used[pos] + 1;
                        q.push(a);
                    }
                }
            }

            if (used[end] != INT_MAX)
                return used[end];
        }

        return -1;
    }
};