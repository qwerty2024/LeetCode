class Solution 
{
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) 
    {
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += abs(arr[i] - brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        long long ans2 = 0;

        for (int i = 0; i < n; i++)
        {
            ans2 += abs(arr[i] - brr[i]);
        }

        return min(k + ans2, ans);
    }
};