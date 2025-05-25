class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();

        if (n == 0)
            return {newInterval};

        vector<vector<int>> ans;
        int i = 0;
        
        while (i < n && newInterval[0] > intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        if (i >= n)
        {
            ans.push_back(newInterval);
            return ans;
        }

        int j = i;
        while ((j + 1) < n && newInterval[1] >= intervals[j + 1][0])
        {
            j++;
        }

        if (newInterval[1] < intervals[j][0])
        {
            ans.push_back(newInterval);
            ans.push_back(intervals[j]);
        }
        else
            ans.push_back({min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[j][1])});

        while (++j < n)
        {
            ans.push_back(intervals[j]);
        }

        return ans;
    }
};