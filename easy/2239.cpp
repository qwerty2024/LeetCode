class Solution 
{
public:
    int findClosestNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        bool curr = false;

        int mini = abs(nums[0]);
        if (nums[0] < 0) 
        {
            curr = true;
        }

        for (auto a : nums)
        {
            if (mini == abs(a))
            {
                if (curr && (a > -1))
                {
                    mini = abs(a);
                    curr = false;
                }
            }
            else if (mini > abs(a))
            {
                mini = abs(a);
                if (a < 0)
                {
                    curr = true;
                }
                else
                {
                    curr = false;
                }
            }
        }

        return curr ? mini * (-1) : mini;
    }
};