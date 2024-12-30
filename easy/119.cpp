class Solution
{
public:
    vector<int> getRow(int n)
    {
        if (n == 0) return { 1 };
        if (n == 1) return { 1, 1 };

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(i + 1, 0);
            tmp[0] = 1;
            for (int j = 1; j <= i; j++)
            {
                tmp[j] = ans[j - 1] + ans[j];
            }

            tmp.push_back(1);
            ans = tmp;
        }

        return ans;
    }
};