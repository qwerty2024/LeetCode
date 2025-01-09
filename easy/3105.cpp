class Solution 
{
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 1;
        int j = 0;
        int ans = 1;

        while (j < n)
        {
            j = i;
            while (j < n && nums[j - 1] < nums[j])
                j++;

            ans = max(ans, j - (i - 1));

            i = ++j;
        }

        i = 1;
        j = i;
        while (j < n)
        {
            j = i;
            while (j < n && nums[j - 1] > nums[j])
                j++;

            ans = max(ans, j - (i - 1));

            i = ++j;
        }


        return ans;
    }
};