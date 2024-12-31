class Solution 
{
public:
    int countHillValley(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> tmp;
        tmp.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == tmp[tmp.size() - 1])
                continue;
            else
                tmp.push_back(nums[i]);
        }

        int ans = 0;
        for (int i = 1; i < tmp.size() - 1; i++)
        {
            if (tmp[i] > tmp[i - 1] && tmp[i] > tmp[i + 1])
                ans++;

            if (tmp[i] < tmp[i - 1] && tmp[i] < tmp[i + 1])
                ans++;
        }

        return ans;
    }
};