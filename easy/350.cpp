class Solution 
{
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) 
    {
        unordered_map<int, int> um;
        vector<int> ans;

        for (auto a : n1)
            um[a]++;

        for (int i = 0; i < n2.size(); i++)
        {
            if (um.contains(n2[i]))
            {
                if (um[n2[i]] > 0)
                {
                    um[n2[i]]--;
                    ans.push_back(n2[i]);
                }
            }
        }

        return ans;
    }
};