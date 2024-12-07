class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        if (nums[0] < k) return -1;

        unordered_set<int> s;
        for (auto a : nums)
            s.insert(a);

        s.insert(k);

        return s.size() - 1;
    }
};