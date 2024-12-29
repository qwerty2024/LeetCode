class Solution 
{
public:
    int numPrimeArrangements(int n) 
    {
        int count = 0;
        unordered_set<int> us{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

        for (int i = 2; i <= n; i++)
        {
            if (us.contains(i)) count++;
        }

        const int mod = 1000000007;
        long long ans = 1;
        for (int i = count; i > 1; i--)
        {
            ans *= i;
            ans %= mod;
        }

        for (int i = n - count; i > 1; i--)
        {
            ans *= i;
            ans %= mod;
        }

        return (int)ans;
    }
};