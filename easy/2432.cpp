class Solution 
{
public:
    int hardestWorker(int n, vector<vector<int>>& logs) 
    {
        unordered_map<int, int> um;
        um[logs[0][0]] = logs[0][1];

        for (int i = 1; i < logs.size(); i++)
        {
            if (um.contains(logs[i][0]))
                um[logs[i][0]] = max(um[logs[i][0]], logs[i][1] - logs[i - 1][1]);
            else
                um[logs[i][0]] = logs[i][1] - logs[i - 1][1];
        }

        int id = -1;
        int maxi = -1;

        for (auto a : um)
        {
            //cout << a.first << " " << a.second << endl;
            if (maxi == a.second)
            {
                if (id > a.first)
                    id = a.first;
            }
            else if (maxi < a.second)
            {
                maxi = a.second;
                id = a.first;
            }
        }

        return id;
    }
};