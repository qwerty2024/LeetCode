class Solution 
{
    int summa(int n)
    {
        int res = 0;

        while (n > 0)
        {
            res += n % 10;
            n /= 10;
        }

        return res;
    }

public:
    int countLargestGroup(int n) 
    {
        unordered_map<int, int> um;

        for (int i = 1; i <= n; i++)
        {
            um[summa(i)]++;
        }   

        int maxi = 0;
        int count = 0;
        for (const auto& a : um)
        {
            if (a.second == maxi)
            {
                count++;
            }
            else if (maxi < a.second)
            {
                maxi = a.second;
                count = 1;
            }
        }

        return count;
    }
};