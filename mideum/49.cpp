class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n = strs.size();
        unordered_map<string, int> um;
        int curr_ind = 0;
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            vector<int> tmp(26, 0);
            for (const auto& a : strs[i])
            {
                tmp[a - 'a']++;
            }

            string key = "";
            for (int j = 0; j < 26; j++)
            {
                key += to_string(tmp[j]);
                key += 'a' + j;
            }

            if (um.contains(key))
            {
                ans[um[key]].push_back(strs[i]);
            }
            else
            {
                um[key] = curr_ind;
                ans.push_back({""});
                ans[curr_ind][0] = strs[i];
                curr_ind++;
            }
        }
        
        return ans;
    }
};