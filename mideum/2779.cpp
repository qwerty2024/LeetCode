class Solution 
{
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        int right = 0;
        int curr = 0;
        while (right < n)
        {
            while (right < n && nums[curr] + k >= nums[right] - k)
            {
                right++;
            }

            ans = max(ans, right - curr);

            curr++;
            right++;
        }


        return ans;
    }
};