class Solution 
{
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int n = nums.size();

        map<int, int, greater<>> m;

        for (auto a : nums)
            m[a]++;

        if (k == 1)
        {
            for (auto a : m)
            {
               if (a.second == 1)
                   return a.first;
            }

            return -1;
        }
        else if (k == n)
        {
            return m.begin()->first;
        }
        else
        {
            int a = nums[0];
            int b = nums[n - 1];

            if (m[a] == 1 && m[b] == 1)
            {
                return max(a, b);
            }
            else if (m[a] == 1)
            {
                return a;
            }
            else if (m[b] == 1)
            {
                return b;
            }
        }

        return -1;
    }
};