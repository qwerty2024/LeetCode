class Solution 
{
    long long sum_z(long long n)
    {
        long long ans = 0;

        while (n > 0)
        {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }

        return ans;
    }

public:
    bool isHappy(int n) 
    {
        unordered_set<long long> us;

        long long ans = (long long)n;
        us.insert(ans);

        while (true)
        {
            ans = sum_z(ans);

            if (us.contains(ans))
                break;

            us.insert(ans);
        }

        return ans == 1 ? true : false;
    }
};