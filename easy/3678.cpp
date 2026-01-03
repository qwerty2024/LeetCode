class Solution 
{
public:
    int smallestAbsent(vector<int>& nums) 
    {
        unordered_set<int> us;
        double sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            us.insert(nums[i]);
            sum += nums[i];
        }

        sum /= nums.size();
        sum += 1.0;

        if (sum <= 1.0)
            sum = 1.0;

        for (int i = (int)floor(sum); i <= 101; i++)
        {
            if (!us.contains(i))
                return i;
        }

        return 0;
    }
};