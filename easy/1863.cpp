class Solution 
{
    int ans = 0;
    int n = 0;

    void dfs(vector<int>& nums, int curr, int i)
    {
        if (i == n) return;

        dfs(nums, curr, i + 1);

        curr ^= nums[i];

        ans += curr;

        dfs(nums, curr, i + 1);
    }

public:
    int subsetXORSum(vector<int>& nums) 
    {
        n = nums.size();

        dfs(nums, 0, 0);

        return ans;    
    }
};

/*
class Solution 
{
public:
    int subsetXORSum(vector<int>& nums) 
    {
        int i = 0;
        for (const int& n: nums)
            i |= n;

        //cout << (i << (nums.size() - 1));

        return i << (nums.size() - 1);
    }
};
*/