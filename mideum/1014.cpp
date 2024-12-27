class Solution 
{
public:
    int maxScoreSightseeingPair(vector<int>& v) 
    {
        int n = v.size();
        int ans = 0;
        vector<int> tmp(n, 0);

        int curr = v[0];
        tmp[0] = curr;
        for (int i = 1; i < n; i++)
        {
            curr--;
            tmp[i] = curr;

            if (curr < v[i])
                curr = v[i];
        }

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, tmp[i] + v[i]);
        }

        return ans;
    }
};