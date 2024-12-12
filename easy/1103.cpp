class Solution 
{
public:
    vector<int> distributeCandies(int cnd, int n) 
    {
        vector<int> ans(n, 0);

        int count = 0;
        int i = 0;
        while (cnd > count)
        {
            count++;
            ans[i] += count;
            cnd -= count;
            i++;
            i %= n;
        }

        if (cnd > 0)
            ans[i] += cnd;

        return ans;
    }
};