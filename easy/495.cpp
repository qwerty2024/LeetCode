class Solution 
{
public:
    int findPoisonedDuration(vector<int>& tS, int d) 
    {
        int ans = d;
        int curr = tS[0] + d;
        int n = tS.size();
        for (int i = 1; i < n; i++)
        {
            ans += d;
            if (tS[i] < curr)
            {
                ans -= (curr - tS[i]);
            }
            
            curr = tS[i] + d;
        }

        return ans;
    }
};