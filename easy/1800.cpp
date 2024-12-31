class Solution 
{
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[j - 1])
                    sum += nums[j];
                else
                    break;    
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};