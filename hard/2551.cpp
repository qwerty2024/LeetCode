class Solution 
{
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        long long ans = 0;

        vector<int> tmp(n - 1, 0);

        for (int i = 1; i < n; i++)
        {
            tmp[i - 1] = weights[i] + weights[i - 1];
        }

        sort(tmp.begin(), tmp.end());

        for (int i = 0; i < k - 1; i++)
        {
            ans += (tmp[n - 2 - i] - tmp[i]);
        }

        return ans;
    }
};