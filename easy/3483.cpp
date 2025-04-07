class Solution 
{
    int test(const vector<int>& dig, int num)
    {
        vector<int> tmp(10, 0);

        while (num > 0)
        {
            tmp[num % 10]++;
            num /= 10;
        }

        for (int i = 0; i < 10; i++)
        {
            if (dig[i] < tmp[i])
                return 0;
        }

        return 1;
    }

public:
    int totalNumbers(vector<int>& digits) 
    {
        int ans = 0;
        vector<int> dig(10, 0);
        for(auto a : digits)
            dig[a]++;

        for (int i = 100; i < 1000; i++)
        {
            if (!(i&1))
            {
                ans += test(dig, i);
            }
        }

        return ans;
    }
};