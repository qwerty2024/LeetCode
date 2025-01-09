class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> um;
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (j < n && j <= k)
        {
            um[nums[j]]++;
            if (um[nums[j]] > 1) return true;
            j++;
        }

        while (j < n)
        {
            um[nums[i]]--;
            um[nums[j]]++;

            if (um[nums[j]] > 1) return true;

            i++;
            j++;
        }

        return false;
    }
};