class Solution 
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        vector<int> ans(3, 0);
        int n = nums.size();
        vector<long long> suff(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + nums[i];
        }

        vector<long long> dp(n, 0);

        for (int i = 0; i <= n - k; i++)
        {
            dp[i] = suff[i] - suff[i + k];
        }


        vector<pair<long long, int>> tmp_left(n, {0, 0});
        for (int i = k; i < n; i++)
        {
            if (tmp_left[i - 1].first >= dp[i - k])
            {
                tmp_left[i] = tmp_left[i - 1];
            }
            else
            {
                tmp_left[i] = {dp[i - k], i - k};    
            }
        }

        vector<pair<long long, int>> tmp_right(n, {0, 0});
        for (int i = n - 2 * k; i >= k; i--)
        {
            if (tmp_right[i + 1].first > dp[i + k])
            {
                tmp_right[i] = tmp_right[i + 1];
            }
            else
            {
                tmp_right[i] = {dp[i + k], i + k};    
            }
        }


        //for (int i = 0; i < n; i++)
        //    cout << dp[i] << " ";
        //cout << endl;

        //for (int i = 0; i < n; i++)
        //    cout << tmp_left[i].first << "[" << tmp_left[i].second << "] ";
        //cout << endl;

        //for (int i = 0; i < n; i++)
        //    cout << tmp_right[i].first << "[" << tmp_right[i].second << "] ";
        //cout << endl;

        int ind = -1;
        int maxi = -1;
        for (int i = k; i <= n - 2 * k; i++)
        {
            if (maxi < dp[i] + tmp_left[i].first + tmp_right[i].first)
            {
                maxi = dp[i] + tmp_left[i].first + tmp_right[i].first;
                ind = i;
            }
        }

        ans[0] = tmp_left[ind].second;
        ans[1] = ind;
        ans[2] = tmp_right[ind].second;

        return ans;
    }
};