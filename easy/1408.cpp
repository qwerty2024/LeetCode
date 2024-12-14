class Solution 
{
public:
    vector<string> stringMatching(vector<string>& words) 
    {   
        set<string> s;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    if (words[j].find(words[i]) != std::string::npos)
                        s.insert(words[i]);
                }
            }
        }
        
        vector<string> ans;
        for (auto a : s)
            ans.push_back(a);

        return ans;
    }
};