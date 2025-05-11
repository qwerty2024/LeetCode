class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();

        k = k % n;

        if (k == 0)
            return;

        int start = 0;
        int indx = 0;
        int tmp = nums[0];

        for (int i = 0; i < n; i++)
        {
            int tmp2 = nums[(indx + k) % n];
            nums[(indx + k) % n] = tmp;
            tmp = tmp2;

            indx += k;
            indx %= n;

            if (start == indx)
            {
                indx++;
                start++;
                tmp = nums[start];
            }
        }
    }
};