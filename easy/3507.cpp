class Solution 
{
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        int count = 0;
        int n = nums.size();

        for (int k = 0; k < nums.size(); k++)
        {
            bool test = true;

            if (n == 1)
                return count;

            for (int i = 1; i < n; i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    test = false;
                    break;
                }
            }

            if (test)
                return count;

            int mini = INT_MAX;
            int ind = -1;
            for (int i = 1; i < n; i++)
            {
                if (mini > nums[i] + nums[i - 1])
                {
                    mini = nums[i] + nums[i - 1];
                    ind = i;
                }
            }

            nums[ind - 1] += nums[ind];

            for (int i = ind; i < n - 1; i++)
            {
                nums[i] = nums[i + 1];
            }

            n--;
            count++;
        }

        return count;
    }
};