class Solution 
{
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        unordered_map<int, int> um;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == key)
                um[nums[i + 1]]++;
        }

        int t = (*um.begin()).first;
        for (auto a : um)
        {
            if (a.second > um[t])
                t = a.first;
        }

        return t;
    }
};