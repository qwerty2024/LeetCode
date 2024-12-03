class Solution 
{
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                m[nums[i][j]]++;

        int k = nums.size();

        vector<int> ans;
        for (auto a : m)
            if (a.second == k) ans.push_back(a.first);
        
        return ans;
    }
};