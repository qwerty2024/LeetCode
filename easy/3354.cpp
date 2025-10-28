class Solution 
{
    bool test(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                return false;
        }

        return true;
    }

    int move_direction(vector<int> nums, int curr, bool direction)
    {
        int n = nums.size();
        while (curr >= 0 && curr < n)
        {
            if (nums[curr] != 0)
            {
                nums[curr]--;
                direction = !direction;
            }

            if (!direction)
            {
                curr--;
            }
            else
            {
                curr++;
            }
        }

        return test(nums) ? 1 : 0;
    }

public:
    int countValidSelections(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans += move_direction(nums, i, false);
                ans += move_direction(nums, i, true);
            }
        }

        return ans;
    }
};