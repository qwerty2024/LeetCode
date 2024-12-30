class Solution 
{
public:
    int tribonacci(int n) 
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        vector<int> tmp{0, 1, 1};

        int i = 3;
        while (i <= n)
        {
            tmp.push_back(tmp[i - 1] + tmp[i - 2] + tmp[i - 3]);
            i++;
        }

        return tmp[n];
    }
};