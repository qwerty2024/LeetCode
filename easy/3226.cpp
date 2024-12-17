class Solution 
{
public:
    int minChanges(int n, int k) 
    {
        int ans = 0;

        while (n > 0)
        {
            if (n % 2 == 0 && k % 2 == 1)
                return -1;
            else if (n % 2 == 1 && k % 2 == 0)
                ans++;
            
            n >>= 1;
            k >>= 1;
        }

        if (n < k) return -1;

        if (n > k) ans += __popcount(n);

        return ans;
    }
};