class Solution 
{
public:
    int averageValue(vector<int>& nums) 
    {
        int sum = 0;
        int count = 0;

        for (auto a : nums)
        {
            if (a % 2 == 0 && a % 3 == 0)
            {
                sum += a;
                count++;
            }
        }

        return (count == 0) ? 0 : sum / count;
    }
};