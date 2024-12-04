class Solution 
{
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string> ans;

        int i = 0;
        while (i < s.size())
        {
            string tmp = "";
            int count = 0;
            while (i < s.size() && count < k)
            {
                tmp += s[i];
                count++;
                i++;
            }

            ans.push_back(tmp);
        }

        for (int j = ans[ans.size() - 1].size(); j < k; j++)
        {
            ans[ans.size() - 1] += fill;
        }

        return ans;
    }
};