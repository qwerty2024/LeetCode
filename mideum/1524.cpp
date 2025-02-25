class Solution 
{
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size();

        vector<long long> chet(n + 1, 0);
        vector<long long> n_chet(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (arr[i - 1] % 2 == 0)
            {
                n_chet[i] = n_chet[i - 1];
                chet[i] = chet[i - 1];

                chet[i]++;
            }
            else
            {
                n_chet[i] = chet[i - 1];
                chet[i] = n_chet[i - 1];

                n_chet[i]++;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++)
            ans = (ans + n_chet[i]) % 1000000007;

        return ans;
    }
};