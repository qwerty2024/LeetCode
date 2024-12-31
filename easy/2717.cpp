class Solution 
{
public:
    int semiOrderedPermutation(vector<int>& nums) 
    {
        int id_1 = -1;
        int id_n = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                id_1 = i;
            if (nums[i] == n)
                id_n = i;
        }

        if (id_1 < id_n)
            return id_1 + n - id_n - 1;
        
        return id_1 + n - id_n - 2; 
    }
};