class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            um[nums[i]] = i;
        }

        vector<int> indexes(n, -1);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (indexes[i] == -1)
            {
                int counter = 1;
                for (int num = nums[i] - 1; ; num--)
                {
                    if (um.contains(num) && indexes[um[num]] == -1)
                    {
                        indexes[um[num]] = i;
                        counter++;
                    }
                    else
                        break;
                }

                for (int num = nums[i] + 1; ; num++)
                {
                    if (um.contains(num) && indexes[um[num]] == -1)
                    {
                        indexes[um[num]] = i;
                        counter++;
                    }
                    else
                        break;
                }

                ans = max(ans, counter);
            }
        }

        return ans;
    }
};