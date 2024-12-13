class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if (n < 1) return false;

        if (__popcount(n) == 1)
        {
            if ((n & 0x55555555) == n)
                return true;
            else
                return false;
        }

        return false;
    }
};