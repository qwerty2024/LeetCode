class Solution 
{
public:
    int numOfWays(int n) 
    {
        long long dv = 6;
        long long tr = 6;
        int mod = 1000000007;

        for (int i = 1; i < n; i++)
        {
            int dv1 = ((dv * 2) % mod + (tr * 2) % mod) % mod; 
            int tr1 = ((tr * 3) % mod + (dv * 2) % mod) % mod;
            dv = dv1;
            tr = tr1;
        }

        return (int)((dv + tr) % mod);        
    }
};