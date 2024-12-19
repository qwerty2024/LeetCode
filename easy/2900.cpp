class Solution 
{
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) 
    {
        int n = w.size();
        vector<string> ans;

        bool test = g[0] == 1 ? true : false;
        ans.push_back(w[0]);
        for (int i = 0; i < n; i++)
        {
            if (test)
            {
                if (g[i] == 0)
                {
                    ans.push_back(w[i]);
                    test = false;
                }
            }
            else
            {
                if (g[i] == 1)
                {
                    ans.push_back(w[i]);
                    test = true;
                }
            }
        }

        return ans;
    }
};