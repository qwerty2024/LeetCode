class Solution 
{
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        unordered_set<string> ans;

        for (auto a : words)
        {
            for (auto b : words)
            {
                if (a != b)
                {
                    if (a.find(b) != string::npos)
                        ans.insert(b);
                }
            }
        }

        return {ans.begin(), ans.end()};
    }
};