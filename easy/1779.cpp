class Solution 
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int mini = INT_MAX;
        int idx = -1;
        
        for (int i = 0; i < points.size(); i++)
        {
            if (x == points[i][0])
            {
                if (mini > abs(points[i][1] - y))
                {   
                    mini = abs(points[i][1] - y);
                    idx = i;
                }
                continue;
            }

            if (y == points[i][1])
            {
                if (mini > abs(points[i][0] - x))
                {   
                    mini = abs(points[i][0] - x);
                    idx = i;
                }
                continue;
            }
        }

        return idx;
    }
};