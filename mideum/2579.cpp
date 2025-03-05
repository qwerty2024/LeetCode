class Solution 
{
    vector<long long> data;

public:
    Solution()
    {
        data.resize(100010, 0);

        data[0] = 0;
        data[1] = 1;

        for (int i = 0; i < 100001; i++)
        {
            data[i + 2] = data[i + 1] + ((long long)i) * 4 + 4;
        }
    }

    long long coloredCells(int n) 
    {
        return data[n];
    }
};