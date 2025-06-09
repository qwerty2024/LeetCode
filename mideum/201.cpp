class Solution 
{
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        if (left == 0)
            return 0;

        int ans = left & right;
        long long diff = 1;
        while (left + diff < right)
        {
            ans = (ans | diff) ^ diff;
            diff <<= 1;
        }

        return ans;
    }
};