class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        if (n < 5)
            return 0;

        int ans = 0;
        int curr = 5;
        while (curr <= n)
        {
            if (curr % 3125 == 0)
            {
                ans += 5;
            }
            else if (curr % 625 == 0)
            {
                ans += 4;
            }
            else if (curr % 125 == 0)
            {
                ans += 3;
            }
            else if (curr % 25 == 0)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }

            curr += 5;
        }
        return ans;
    }
};