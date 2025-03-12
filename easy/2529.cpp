class Solution 
{
public:
    int maximumCount(vector<int>& nums) 
    {
        int pos = 0;
        while (pos < nums.size() && nums[pos] < 0)
            pos++;

        int neg = pos;
        while (pos < nums.size() && nums[pos] == 0)
            pos++;

        pos = nums.size() - pos;

        return max(pos, neg);
    }
};