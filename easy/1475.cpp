class Solution 
{
public:
    vector<int> finalPrices(vector<int>& p) 
    {
        vector<int> ans(p.size());
        for (int i = 0; i < p.size(); i++)
        {
            int sk = 0;
            for (int j = i + 1; j < p.size(); j++)
            {
                if (p[j] <= p[i]) 
                {
                    sk = p[j];
                    break;
                }
            }
            ans[i] = p[i] - sk;
        }

        return ans;
    }
};