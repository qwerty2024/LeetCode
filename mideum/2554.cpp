class Solution 
{
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        unordered_set<int> us;

        for (auto a : banned)
        {
            us.insert(a);
        }

        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!us.contains(i))
            {
                if (sum + i <= maxSum)
                {
                    sum += i;
                    count++;
                }
                else
                    break;
            }
        }

        return count;
    }
};