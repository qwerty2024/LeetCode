class Solution 
{
public:
    int countTriples(int n) 
    {
        unordered_set<int> quad;
        for (int i = 0; i < n; i++)
            quad.insert((i + 1) * (i + 1));

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (quad.contains(i * i + j * j))
                    ans += 2;
            }
        }
        
        return ans;
    }
};