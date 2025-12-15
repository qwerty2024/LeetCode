class Solution 
{
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        long long ans = 0;
        int n = prices.size();
        
        if (n == 1)
            return 1;

        int len = 1;

        for (int i = 0; i < n; i++)
        {
            if (i != n - 1 && prices[i] - prices[i + 1] == 1)
            {
                len++;
                ans += len;
                continue;
            }
            
            len = 1;
            ans += len;
        }

        return ans;
    }
};