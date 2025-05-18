class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();

        if (n == 1)
            return nums[0] == target ? 0 : -1;

        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                if (mid > 0 && nums[mid - 1] > nums[mid])
                {
                    l = mid;
                    break;
                }
                r = mid - 1;
            }
        }

        if (target <= nums[n - 1])
        {
            r = n - 1;
        }
        else
        {
            r = l;
            l = 0;
        }

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};