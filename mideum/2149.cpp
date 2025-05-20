class Solution 
{
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        int minus = 0;
        int plus = 0;

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                // нечетн
                while (nums[minus] > 0)
                {
                    minus++;
                }

                ans[i] = nums[minus];

                minus++;
            }
            else
            {
                // четн

                while (nums[plus] < 0)
                {
                    plus++;
                }

                ans[i] = nums[plus];

                plus++;
            }
        }

        return ans;
    }
};