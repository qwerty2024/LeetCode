class Solution 
{
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> v_max(26, 0);

        for (auto& a : words2)
        {
            vector<int> tmp(26, 0);
            
            for (auto& b : a)
                tmp[b - 'a']++;

            for (int i = 0; i < 26; i++)
            {
                v_max[i] = max(v_max[i], tmp[i]);
            }
        }

        vector<string> ans;
        
        for (auto& a : words1)
        {
            bool flag = true;

            vector<int> tmp(26, 0);
            
            for (auto& b : a)
                tmp[b - 'a']++;

            for (int i = 0; i < 26; i++)
            {
                if (tmp[i] < v_max[i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag) ans.push_back(a);
        }

        return ans;
    }
};