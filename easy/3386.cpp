class Solution 
{
public:
    int buttonWithLongestTime(vector<vector<int>>& ev) 
    {
        int maxi = ev[0][1];
        int n = ev.size();
        int ans = ev[0][0];
        for (int i = 1; i < n; i++)
        {
            if (maxi < ev[i][1] - ev[i - 1][1])
            {
                maxi = ev[i][1] - ev[i - 1][1];
                ans = ev[i][0];
            }
            else if (maxi == ev[i][1] - ev[i - 1][1])
            {
                if (ans > ev[i][0])
                {
                    maxi = ev[i][1] - ev[i - 1][1];
                    ans = ev[i][0];
                }
            }
        }

        return ans;
    }
};