class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (ans[count][1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
                count++;
            }
            else
            {
                ans[count][1] = max(ans[count][1], intervals[i][1]);
            }
        }

        return ans;
    }
};