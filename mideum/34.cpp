class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        if (n == 0)
            return {-1, -1};

        int left = -1;
        int right = -1;

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
               
        if (nums[l] != target)
            return {-1, -1};
        
        left = r;

        l = 0;
        r = n - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (nums[l] == target)
            right = l;
        else
            right = l - 1;

        return {left, right};
    }
};