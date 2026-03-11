class Solution 
{
public:
    int findComplement(int num) 
    {
        int ans = 0;

        if (num == 0)
            return 1;

        long long step = 1;
        while (num > 0)
        {
            if (!(num & 1))
                ans += step;

            step <<= 1;
            num >>= 1;
        }

        return ans;
    }
};