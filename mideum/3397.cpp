class Solution 
{
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {nums[i] - k, nums[i] + k};
        }

        int curr = v[0].first;
        nums[0] = curr;
        for (int i = 1; i < n; i++)
        {
            curr++;
            if (curr >= v[i].first && curr <= v[i].second)
            {
                nums[i] = curr;
            }
            else if(curr > v[i].second)
            {
                curr = v[i].second;
                nums[i] = curr;
            }
            else
            {
                curr = v[i].first;
                nums[i] = curr;
            }
        }    

        //for (int i = 0; i < n; i++)
        //{
        //    cout << nums[i] << " ";
        //}
        
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else
                ans++;
        }

        return ans;
    }
};