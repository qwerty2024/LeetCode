class Solution 
{
public:
    int minimumRightShifts(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = 1; j < n; j++)
            {
                if (nums[j] < nums[j - 1])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                return i;

            int save = nums[n - 1];
            for (int j = n - 2; j >= 0; j--)
                nums[j + 1] = nums[j];
            nums[0] = save;
        }

        return -1;
    }
};