class Solution 
{
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) 
    {
        int n = original.size();

        //if (original[0] < bounds[0][0] || original[0] > bounds[0][1])
        //    return 0;
        
        int lower = original[0] - bounds[0][0];
        int upper = bounds[0][1] - original[0];

        for (int i = 1; i < n; i++)
        {
            //if (original[i] < bounds[i][0] || original[i] > bounds[i][1])
            //    return 0;

            lower = min(lower, original[i] - bounds[i][0]);
            upper = min(upper, bounds[i][1] - original[i]);
        }

        return (upper + lower + 1) > 0 ? (upper + lower + 1) : 0;
    }
};