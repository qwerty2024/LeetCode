class Solution 
{
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) 
    {
        unordered_map<int, unordered_map<int, int>> m;

        for (auto a : pick)
        {
            m[a[0]][a[1]]++;
        }

        int ans = 0;

        for (auto a : m)
        {
            for (auto b : a.second)
            {
                if (a.first < b.second)
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};