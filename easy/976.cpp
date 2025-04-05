class Solution 
{
public:
    int largestPerimeter(vector<int>& nums) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<>());

        int ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            int a = nums[i + 0];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if (a + b > c && a + c > b && b + c > a)
                ans = max(ans, a + b + c);
        }

        return ans;
    }
};