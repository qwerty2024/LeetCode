class Solution
{
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long ans = n;
        map<int, int> um;

        while (i < n - 1 && j <= n)
        {
            while (j < n)
            {
                um[nums[j]]++;
                auto mini = um.begin();
                auto maxi = --um.end();      
                if ((*maxi).first - (*mini).first > 2) break;  
                j++;
            }

            long long count = j - i - 1;
            ans += ((1 + count) * count) / 2;


            if (j < n)
            {
                while (i <= j)
                {
                    um[nums[i]]--;

                    if (um[nums[i]] == 0) um.erase(nums[i]);

                    auto mini = um.begin();
                    auto maxi = --um.end();
                    i++;
                    if ((*maxi).first - (*mini).first <= 2) break;                   
                }
            }
            else
                break;

            count = j - i - 1;
            ans -= ((1 + count) * count) / 2;
            j++;
        }

        return ans;
    }
};