class Solution 
{
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();

        vector<bool> used(n, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!used[j] && fruits[i] <= baskets[j])
                {
                    used[j] = true;
                    break;
                }
            }
        }

        int ans = 0;
        for (auto a : used)
            if (!a)
                ans++;

        return ans;
    }
};