class Solution 
{
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); i++)
        {
            int j = 0;
            for (; j < nums.size(); j++)
            {
                if (nums[j] >= i)
                    break;
            }

            if (i == nums.size() - j)
                return i;
        }

        return -1;
    }
};