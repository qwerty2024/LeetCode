class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int ans = 0;

        int current = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] > current)
            {
                current = prices[i]; 
            }
            else
            {
                while (i > 0 && prices[i - 1] < prices[i])
                {
                    i--;
                }

                ans += current - prices[i];
                current = prices[i];
            }
        }

        return ans;
    }
};