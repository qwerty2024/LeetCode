class Solution 
{
public:
    int specialTriplets(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            if (um.contains(nums[i] * 2))
                pref[i] = um[nums[i] * 2];

            um[nums[i]]++;
        }

        um.clear();

        for (int i = n - 1; i > 0; i--)
        {
            if (um.contains(nums[i] * 2))
                suff[i] = um[nums[i] * 2];

            um[nums[i]]++;
        }

        //for (auto a : pref)
        //    cout << a << " ";
        //cout << endl;

        //for (auto a : suff)
        //    cout << a << " ";
        //cout << endl;

        for (int i = 1; i < n - 1; i++)
        {
            ans = (ans + ((long long)pref[i] * suff[i]) % 1000000007) % 1000000007;
        }

        return ans;    
    }
};