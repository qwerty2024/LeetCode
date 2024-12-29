class Solution 
{
public:
    int distinctAverages(vector<int>& nums) 
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        //for (auto a : nums)
        //    cout << a << " ";
        //cout << endl;

        unordered_set<double> us;

        for (int i = 0; i < n / 2; i++)
        {
            double a = (double)(nums[i] + nums[n - 1 - i]) / 2;
            //cout << a << " ";
            us.insert(a);
        }

        return us.size();
    }
};