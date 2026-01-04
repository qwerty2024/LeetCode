class Solution 
{
public:
    long long minCuttingCost(int n, int m, int k) 
    {
        if (n <= k && m <= k)
            return 0;

        if (n < m)
        {
            return (long long)(m - k) * k;
        }
        else
        {
            return (long long)(n - k) * k;
        }

        return 0;
    }
};