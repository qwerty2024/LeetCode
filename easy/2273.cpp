class Solution 
{
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        int n = words.size();
        vector<bool> use(n, true);
        vector<string> ans;
        vector<vector<int>> tmp(n, vector<int>(26, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                tmp[i][words[i][j] - 'a']++;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (use[i])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (use[j])
                    {
                        bool test = true;
                        for (int k = 0; k < 26; k++)
                        {
                            if (tmp[i][k] != tmp[j][k])
                            {
                                test = false;
                                break;
                            }
                        }
                        if (test)
                        {
                            use[j] = false;
                        }
                        else
                        {
                            i = j - 1;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (use[i])
                ans.push_back(words[i]);
        }

        return ans;
    }
};