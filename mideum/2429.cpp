class Solution 
{
public:
    int minimizeXor(int num1, int num2) 
    {
        int m = __popcount(num1);
        int n = __popcount(num2);

        string tmp = "000000000000000000000000000000";
        int s = tmp.size() - 1;
        while (num1 > 0)
        {
            if (num1 % 2 == 1)
                tmp[s] = '1';

            s--;
            num1 >>= 1;
        }

        if (n <= m)
        {
            int count = m - n;
            for (int i = tmp.size() - 1; i >= 0 && count > 0; i--)
            {
                if (tmp[i] == '1')
                {
                    tmp[i] = '0';
                    count--;
                }
            }
        }
        else
        {
            int count = n - m;
            for (int i = tmp.size() - 1; i >= 0 && count > 0; i--)
            {
                if (tmp[i] == '0')
                {
                    tmp[i] = '1';
                    count--;
                }
            }
        }

        int ans = 0;
        int p = 1;

        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            if (tmp[i] == '1')
            {
                ans += p;
            }

            p *= 2;
        }

        return ans;
    }
};