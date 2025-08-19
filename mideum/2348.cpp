class Solution 
{
    inline long long summa(long long len)
    {
        return ((1 + len) * len) >> 1;
    }

public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();

        while (i < n) 
        {
            if (nums[i] == 0)
            {
                j = i;

                while (j < n)
                {
                    if (nums[j] != 0)
                    {
                        break;
                    }
                    j++;
                }

                ans += summa((long long)(j - i));
                i = j;
            }

            i++;
        }

        return ans;
    }
};