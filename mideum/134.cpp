class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++)
        {
            diff[i] = cost[i] - gas[i];
        }

        int i = 0;
        int current = 0;
        int start = 0;
        while (i < n)
        {
            current += diff[i];

            if (current > 0)
            {
                current = 0;
                start = i + 1;
            }

            i++;
        }

        i = 0;
        current = 0;
        for (; i < n; i++)
        {
            current += diff[(start + i) % n];
            if (current > 0)
                return -1;
        }

        return start;
    }
};