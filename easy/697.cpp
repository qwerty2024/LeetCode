class Solution 
{
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        vector<int> freq(50001, 0);

        for (auto a : nums)
            freq[a]++;

        int d = *max_element(freq.begin(), freq.end());
        if (d == 1) return 1;

        unordered_map<int, pair<int, int>> um;

        for(int i = 0; i < freq.size(); i++)
        {
            if (freq[i] == d)
                um[i] = {0, 0};
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (um.contains(nums[i]))
            {
                if (freq[nums[i]] == d)
                {
                    um[nums[i]].first = i;
                }

                freq[nums[i]]--;

                if (freq[nums[i]] == 0)
                {
                    um[nums[i]].second = i;
                }
            }
        }

        int len = INT_MAX;

        for (auto a : um)
        {
            len = min(a.second.second - a.second.first, len);
        }

        return len + 1;
    }
};