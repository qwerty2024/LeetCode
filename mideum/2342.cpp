class Solution 
{
    int summ(int n)
    {
        int ans = 0;

        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }

public:
    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        //vector<int> z(n, 0);

        unordered_map<int, multiset<int, greater<>>> um;

        for (int i = 0; i < n; i++)
        {
            int tmp = summ(nums[i]);
            um[tmp].insert(nums[i]);
        }
      
        int ans = 0;

        for (auto a : um)
        {
            auto it1 = a.second.begin();
            auto it2 = it1;
            it2++;

            if (it2 == a.second.end()) continue;

            ans = max(ans, *it1 + *it2);
        }

        return ans ? ans : -1;
    }
};