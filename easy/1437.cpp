class Solution 
{
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        if (k == 0) return true;

        int n = nums.size();
        int i = 0;
        int j = 0;
        
        while (j < n && i < n)
        {
            while (i < n && nums[i] == 0)
            {
                i++;
            }

            j = i + 1;
            while (j < n && nums[j] == 0)
            {
                j++;
            }

            if (j >= n || i >= n)
                break;

            if (j - i - 1 < k)
                return false;

            i = j;
        }

        return true;
    }
};