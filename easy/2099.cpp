class Solution 
{
    struct Cmp
    {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second < b.second;
        }
    };

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end(), greater<>());

        v.resize(k);

        sort(v.begin(), v.end(), Cmp());

        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = v[i].first;
        }

        return ans;
    }
};