class Solution 
{
    int number_max(int n)
    {
        int maxi = 0;
        while (n > 0)
        {
            maxi = max(maxi, n % 10);
            n /= 10;
        }

        return maxi;
    }

public:
    int maxSum(vector<int>& nums) 
    {
        vector<int> v(10, 0);

        int maxi = -1;
        for (auto a : nums)
        {
            int ind = number_max(a);

            if (v[ind] != 0)
            {
                maxi = max(maxi, a + v[ind]);
                v[ind] = max(v[ind], a);
            }
            else
            {
                v[ind] = a;
            }
        }

        return maxi;
    }
};