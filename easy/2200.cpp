class Solution 
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        unordered_set<int> tmp;
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] == key)
            {
                int begin = ((i - k < 0) ? 0 : (i - k));
                int end = ((i + k >= n) ? (n - 1) : (i + k));

                //cout << begin << " " << end << endl;
                for (; begin <= end; begin++)
                    tmp.insert(begin);
            }

            i++;
        }

        vector<int> ans;

        for (auto a : tmp)
            ans.push_back(a);

        sort(ans.begin(), ans.end());

        return ans;
    }
};