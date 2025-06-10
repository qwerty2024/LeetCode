class Solution 
{
public:
    double myPow(double x, int n) 
    {
        bool flag = false;
        if (n == -2147483648)
        {
            x = 1 / x;
            n = 2147483647;
            flag = true;
        }

        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        vector<bool> bits(31, false);
        for (int i = 30; i >= 0; i--)
        {
            if (n & 1)
                bits[i] = true;
            n >>= 1;
        }

        double ans = 1;
        for (int i = 0; i < 30; i++)
        {
            if (bits[i])
            {
                ans *= x;
            }

            ans *= ans;
        }

        if (bits[30])
        {
            ans *= x;
        }

        if (flag)
        {
            ans *= x;
        }

        return ans;
    }
};