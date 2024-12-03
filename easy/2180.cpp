class Solution 
{
    bool isEvenSum(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }

        return !(sum % 2);
    }
public:
    int countEven(int num) 
    {
        int ans = 0;

        for (int i = 2; i <= num; i++)
        {
            if (isEvenSum(i))
                ans++;
        }

        return ans;
    }
};