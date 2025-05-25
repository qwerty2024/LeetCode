class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 1;
        int i = 0;

        int mini = points[0][1];
        while (i < n)
        {
            if (points[i][0] <= mini)
            {
                mini = min(mini, points[i][1]);
                i++;
            }
            else
            {
                mini = points[i][1];
                ans++;
            }
        }


        return ans;
    }
};