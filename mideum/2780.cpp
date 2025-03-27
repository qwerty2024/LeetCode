class Solution 
{
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();

        unordered_map<int, int> q;

        for (auto a : nums)
            q[a]++;

        int elem = -1;

        for (auto a : q)
            if (a.second > n / 2)
            {
                elem = a.first;
                break;
            }

        //cout << elem;
        int count_right = q[elem];
        int count_left = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == elem)
            {
                count_right--;
                count_left++;
            }

            if ((count_left > (i + 1) / 2) && (count_right > (n - i - 1) / 2))
                return i;
        }

        return -1;
    }
};